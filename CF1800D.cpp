#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
ll mod = 998244353;
const ll mxn = 2e5+10;
ll pw(ll a,ll b){
	ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        b>>=1;
        a = a*a%mod;
    }
    return re;
}
ll inv(ll k){
    return pw(k,mod-2);
}
pll p = {31,41};
pll pref[mxn];
pll pws[mxn];
pll inv2;
ll mad(ll a,ll b){
    a += b;
    if(a>=mod) a-= mod;
    return a;
}
ll mub(ll a,ll b){
    a = a+mod-b;
    if(a>=mod) a -= mod;
    return a;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<pll> st;
    for(int i = 1;i<=n;i++){
        pref[i].fs = mad(pref[i-1].fs,pws[i-1].fs*(s[i-1]-'a'+1)%mod);
        pref[i].sc = mad(pref[i-1].sc,pws[i-1].sc*(s[i-1]-'a'+1)%mod);
    }
    for(int i = 2;i<=n;i++){
        pll k = {mad(pref[i-2].fs,inv2.fs*mub(pref[n].fs,pref[i].fs)%mod),mad(pref[i-2].sc,inv2.sc*mub(pref[n].sc,pref[i].sc)%mod)};
        st.insert(k);
    }
    cout<<st.size()<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pws[0].fs = pws[0].sc = 1;
    for(int i = 1;i<mxn;i++){
        pws[i].fs = pws[i-1].fs*p.fs%mod;
        pws[i].sc = pws[i-1].sc*p.sc%mod;
    }
    inv2 = {inv(p.fs)*inv(p.fs)%mod,inv(p.sc)*inv(p.sc)%mod};
    int t;
    cin>>t;
    while(t--)solve();
}
