#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    map<ll,ll> mp;
    set<ll> used;
    int n;
    cin>>n;
    vector<int> v(n);
    ll ans = 0;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    for(int i = n-1;i>=0;i--){
        if(mp[v[i]] == 1)mp.erase(v[i]);
        else mp[v[i]]--;
        if(used.find(v[i]) == used.end()){
            used.insert(v[i]);
            ans += mp.size();
        }
    }
    cout<<ans;
}
