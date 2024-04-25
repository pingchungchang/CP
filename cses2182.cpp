#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mod = 1e9+7;
const ll mxn =1e6+10;
const ll mod2 = mod-1;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
ll inv(ll k){
    return pw(k,mod-2);
}
ll inv2(ll k){
    return pw(k,mod2-2);
}
int main(){
    ll n;
    cin>>n;
    pll arr[n];
    for(auto &i:arr)cin>>i.fs>>i.sc;
    ll ans1 = 1;
    for(auto &i:arr){
        ans1 = ans1*(i.sc+1)%mod;
    }
    cout<<ans1<<' ';
    ll ans2 = 1;
    for(auto &i:arr){
        ans2 = ans2*(pw(i.fs,i.sc+1)+mod-1)%mod*inv(i.fs-1)%mod;
    }
    cout<<ans2<<' ';

    ll ans3 = 1;
    ll pref[n],suf[n];
    for(ll i = 0;i<n;i++){
        pref[i] = arr[i].sc+1;
        if(i != 0)pref[i] = pref[i]*pref[i-1]%mod2;
    }
    for(ll i = n-1;i>=0;i--){
        suf[i] = arr[i].sc+1;
        if(i != n-1)suf[i] = suf[i]*suf[i+1]%mod2;
    }
    for(ll i = 0;i<n;i++){
        ans3 = ans3*pw(arr[i].fs,arr[i].sc*(arr[i].sc+1)/2%mod2*(i>0?pref[i-1]:1LL)%mod2*(i<n-1?suf[i+1]:1LL)%mod2)%mod;
    }
    cout<<ans3;
}