#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx2")

#define ll long long
ll n,mod;
const ll mxn = 505;
ll arr[mxn],big[mxn];
bitset<mxn> vis;


ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
#define pll pair<ll,ll>
#define fs first
#define sc second
ll f(ll h){
    vis.reset();
    fill(big,big+mxn,0);
    for(int i = 0;i<n;i++){
        big[i] = (pw(arr[h],arr[i])+pw(arr[i],arr[h]))%mod;
    }
    ll re = 0;
    vis[h] = true;
    for(int i = 0;i<n-1;i++){
        pll p = {-1,-1};
        for(int j = 0;j<n;j++){
            if(vis[j])continue;
            p = max(p,{big[j],j});
        }
        // cout<<p.fs<<' '<<p.sc<<endl;
        vis[p.sc] = true;
        re += p.fs;
        for(int j = 0;j<n;j++){
            big[j] = max(big[j],(pw(arr[p.sc],arr[j])+pw(arr[j],arr[p.sc]))%mod);
        }
    }
    return re;
}
int main(){
    cin>>n>>mod;
    for(int i= 0;i<n;i++)cin>>arr[i];
    ll ans = f(0);
    cout<<ans;
}