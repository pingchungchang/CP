#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mod = 1e9+7;
pll p = {29,31};
const ll mxn = 2020;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1){
            re = re*a%mod;
        }
        b>>=1;
        a = a*a%mod;
    }
    return re;
}
ll inv(ll k){
    return pw(k,mod-2);
}
pll pref[mxn];
pll getval(ll s,ll e){
    pll tmp = {pref[e].fs-pref[s-1].fs+mod,pref[e].sc-pref[s-1].sc+mod};
    tmp.fs %= mod;
    tmp.sc %= mod;
    tmp.fs = tmp.fs*inv(pw(p.fs,s-1))%mod;
    tmp.sc = tmp.sc*inv(pw(p.sc,s-1))%mod;
    return tmp;
}


bool eq(pll a,pll b){
    if(a.fs == b.fs&&a.sc == b.sc)return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    ll n = s.size();
    pll tmp = {1,1};
    for(int i = 1;i<=n;i++){
        pref[i].fs = pref[i-1].fs+tmp.fs*(s[i-1]-'a'+1)%mod;
        pref[i].sc = pref[i-1].sc+tmp.sc*(s[i-1]-'a'+1)%mod;
        pref[i].fs %= mod;
        pref[i].sc %= mod;
        tmp.fs = tmp.fs*p.fs%mod;
        tmp.sc = tmp.sc*p.sc%mod;
    }
    vector<pll> ans;
    for(int i = 1;i<=n;i++){
        for(int j =i;j<=n;j++){
            ll len = j-i+1;
            if(i+len*3-1>n)continue;
            pll a = getval(i,j);
            pll b = getval(j+1,j+len);
            pll c = getval(j+len+1,j+len*2);
            if(eq(b,c)&&!eq(a,b)){
                ans.push_back({i,i+len*3-1});
            }
            // cout<<a.fs<<' '<<a.sc<<' '<<b.fs<<' '<<b.sc<<' '<<c.fs<<' '<<c.sc<<'\n';
        }
    }
    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
}