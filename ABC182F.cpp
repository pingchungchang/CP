#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int main(){
    ll n;
    cin>>n;
    ll x;
    cin>>x;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    map<ll,ll> mp[2];
    mp[0][x] = 1;
    bool roll = 0;
    for(int i = 0;i<n-1;i++){
        roll ^= 1;
        mp[roll].clear();
        for(auto &j:mp[roll^1]){
            // cout<<i<<":"<<roll<<":"<<endl;
            // cout<<j.fs<<','<<j.sc<<endl;
            if(j.fs%arr[i] == 0){
                ll k = j.fs%arr[i+1]/arr[i];
                if(k<arr[i+1]/arr[i])mp[roll][j.fs-k*arr[i]]+=j.sc;
                k = (arr[i+1]/arr[i]-k);
                // k = ((j.fs+arr[i+1]-1)/arr[i+1]*arr[i+1]-j.fs)/arr[i];
                // cout<<j.fs<<","<<k<<endl;
                if(k<arr[i+1]/arr[i])mp[roll][j.fs+k*arr[i]]+=j.sc;
            }
        }
        // for(auto &j:mp[roll])cout<<j.fs<<":"<<j.sc<<',';cout<<endl;
    }
    ll ans = 0;
    for(auto &i:mp[roll]){
        if(i.fs%arr[n-1] == 0)ans += i.sc;
    }
    cout<<ans;
}