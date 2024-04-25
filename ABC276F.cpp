#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
const ll mxn = 2e5+10;
#define pll pair<ll,ll>
#define fs first
#define sc second
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

ll cbit[mxn],sbit[mxn];
void modify(ll bit[],ll p,ll v){
    v %= mod;
    for(;p<mxn;p+=p&-p){
        bit[p] += v;
        if(bit[p]>=mod)bit[p] -= mod;
    }
    return;
}

ll getval(ll bit[],ll s,ll e){
    ll re=  0;
    for(;e>0;e -= e&-e)re += bit[e];
    s--;
    for(;s>0;s -= s&-s){
        if(bit[s]>re)re = re+mod-bit[s];
        else re -= bit[s];
    }
    re %= mod;
    return re;
}
ll arr[mxn];
int main(){
    ll n;
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    ll total = 0;
    for(ll i = 1;i<=n;i++){
        total += getval(sbit,arr[i]+1,mxn-1)%mod*2;
        total += getval(cbit,1,arr[i])*arr[i]%mod*2;
        total += arr[i];
        total %= mod;
        modify(cbit,arr[i],1);
        modify(sbit,arr[i],arr[i]);
        cout<<total*inv(1LL*i*i%mod)%mod<<'\n';
    }
    return 0;
}