#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;

ll calc(ll k,vector<ll> &v){
    ll re = k;
    for(ll i = 1;i<(1LL<<v.size());i++){
        ll x = 1;
        for(ll j = 0;j<v.size();j++){
            if((1<<j)&i)x *= v[j];
        }
        if(__builtin_popcount(i)&1){
            re = re+mod-k/x;
            if(re>=mod)re -= mod;
        }
        else{
            re = re+k/x;
            if(re>=mod)re -= mod;
        }
    }
    // cout<<k<<":";for(auto &i:v)cout<<i<<' ';cout<<":"<<re<<endl;
    return re;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    ll ans = 1;
    for(int i = 0;i<n-1;i++){
        if(arr[i] == arr[i+1]){
            ans = (m/arr[i])*ans%mod;
            continue;
        }
        if(arr[i]%arr[i+1] != 0){
            ans = 0;
            break;
        }
        ll rest = arr[i]/arr[i+1];
        bool flag = true;
        vector<ll> v;
        while(flag){
            flag = false;
            for(ll j = 2;j*j<=rest;j++){
                if(rest%j == 0){
                    if(v.empty()||v.back() != j)v.push_back(j);
                    while(rest%j == 0)rest/=j;
                    flag = true;
                    break;
                }
            }
        }
        // cout<<ans<<',';
        // cout<<arr[i]/arr[i+1]<<' '<<rest<<endl;
        if(rest != 1&&(v.empty()||v.back() != rest))v.push_back(rest);
        // cout<<i<<":";for(auto &j:v)cout<<j<<',';cout<<endl;
        ll k = m/arr[i+1];
        ans = ans*calc(k,v)%mod;
    }
    cout<<ans<<'\n';
    // cout<<endl<<endl;
}

int main(){
    // vector<ll> vv = {2,3,5};
    // cout<<calc(20,vv)<<endl;return 0;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
/*
5
3 5
4 2 1
2 1
1 1
5 50
2 3 5 2 3
4 1000000000
60 30 1 1
2 1000000000
1000000000 2

*/