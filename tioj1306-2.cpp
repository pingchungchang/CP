#include <bits/stdc++.h>
using namespace std;


#define ll long long
string s,ss;

const ll mod = 1e9+7;
const ll p = 37;

ll pw(ll t){
    ll ans = 1;
    ll now = p;
    while(t != 0){
        if((t&1) != 0)ans = (ans*now)%mod;
        now = (now*now)%mod;
        t>>=1;
    }
    return ans;
}
void solve(){
    cin>>ss;
    int n = s.size(),m = ss.size();
    if(m>=n){
        if(s != ss)cout<<0<<'\n';
        else cout<<1<<'\n';
    }
    ll hs = 0,hss = 0;
    for(ll i = 0;i<m;i++){
        hs = hs*p%mod;
        hs += (s[i]-'a');
    }
    hs %= mod;
    for(ll i = 0;i<m;i++){
        hss = hss*p%mod;
        hss += (ss[i]-'a');
    }
    hss%=mod;
    ll ans = 0;
    if(hs == hss)ans++;

    ll power = pw(m-1);
    for(ll i = m;i<n;i++){
        hs = (hs+mod-power*1LL*(s[i-m]-'a')%mod)%mod;
        hs = (hs*p)%mod;
        hs = (hs+s[i]-'a')%mod;
        if(hs == hss)ans++;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        cin>>s;
        int k;
        cin>>k;
        for(int i= 0;i<k;i++)solve();
    }
}
