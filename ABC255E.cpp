
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#define ll long long
#define map unordered_map
const int mxn = 1e5+10;
map<ll,ll> mp[2];
map<ll,ll> cnt[2];
ll arr[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 2;i<=n;i++){
        cin>>arr[i];
        arr[i] = arr[i]-arr[i-1];
    }
    ll diff[m];
    for(auto &i:diff)cin>>i;
    for(int i = 1;i<=n;i++){
        mp[i&1][arr[i]]++;
    }
    ll ans = 0;
    for(int i =1;i<=n;i++){
        for(int j = 0;j<m;j++){
            ll tmp = 0;
            for(int k = 0;k<m;k++){
                tmp += mp[i&1][arr[i]+diff[k]-diff[j]];
                tmp += mp[(i&1)^1][diff[k]+(diff[j]-arr[i])];
                if(mp[i&1][arr[i]+diff[k]-diff[j]] == 0)mp[i&1].erase(arr[i]+diff[k]-diff[j]);
                if(mp[(i&1)^1][diff[k]+diff[j]-arr[i]] == 0)mp[(i&1)^1].erase(diff[k]+diff[j]-arr[i]);
            }
            ans = max(ans,tmp);
        }
    }
    cout<<ans;
}