#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<vector<int>,ll> dp[2];

vector<int> trans(vector<int> tmp,int k){
    for(auto &i:tmp){
        if(i&k){
            i = k;
            return tmp;
        }
    }
    tmp.push_back(k);
    return tmp;
}
void pv(vector<int> v){
    for(auto &i:v)cout<<i<<' ';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    short roll = 0;
    ll ans = 0;
    int arr[n];
    dp[roll][{}] = 1;
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
            roll ^=1;
            dp[roll].clear();
            for(auto &j:dp[roll^1]){
                dp[roll][j.first] = j.second;
            }
            continue;
        }
        roll ^= 1;
        dp[roll].clear();
        for(auto &j:dp[roll^1]){
            dp[roll][trans(j.first,arr[i])] += j.second;
        }
        dp[roll][{}] = 1;
        for(auto &j:dp[roll]){
            ans += 1LL*j.first.size()*j.second;
        }
        for(auto &j:dp[roll]){pv(j.first);cout<<','<<j.second<<';';}
        cout<<'\n';
    }
    for(ll i = 0;i<n;i++){
        if(arr[i] == 0)ans += (i+1)*(n-i);
    }
    cout<<ans;
}