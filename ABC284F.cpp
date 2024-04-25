#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
pll p = {29,31};
const ll mod = 1e9+7;
const ll mxn = 2e6+10;
pll pref[mxn],suf[mxn];
ll n;
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
pll presum(ll s,ll e){
    return {pw(inv(p.fs),s)*(pref[e+1].fs+mod-pref[s].fs)%mod,pw(inv(p.sc),s)*(pref[e+1].sc+mod-pref[s].sc)%mod};
}
pll sufsum(ll s,ll e){
    return {pw(inv(p.fs),n-e-1)*(suf[s].fs-suf[e+1].fs+mod)%mod,pw(inv(p.sc),n-e-1)*(suf[s].sc-suf[e+1].sc+mod)%mod};
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>n>>s;
    n = s.size();
    pref[0] = suf[n] = {0,0};
    pll tmp = {1,1};
    for(int i = 0;i<n;i++){
        pref[i+1].fs = pref[i].fs+tmp.fs*(s[i]-'a'+1);
        pref[i+1].sc = pref[i].sc+tmp.sc*(s[i]-'a'+1);
        pref[i+1].fs %=mod;
        pref[i+1].sc %= mod;
        tmp = {tmp.fs*p.fs%mod,tmp.sc*p.sc%mod};
    }
    tmp = {1,1};
    for(int i = n-1;i>=0;i--){
        suf[i].fs = suf[i+1].fs+tmp.fs*(s[i]-'a'+1);
        suf[i].sc = suf[i+1].sc+tmp.sc*(s[i]-'a'+1);
        suf[i].fs %= mod;
        suf[i].sc %= mod;
        tmp = {tmp.fs*p.fs%mod,tmp.sc*p.sc%mod};
    }
    for(int i = 0;i<n-1;i++){
        if(presum(0,i)+presum(n-i-1,n-1) == sufsum(i+1,n-i-2))
    }
}