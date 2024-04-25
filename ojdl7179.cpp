#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#define ll int
#define fs first
#define sc second
#define pll pair<ll,ll>
#define pii pll
const ll mxn = 1e6+10;
vector<ll> primes;
const ll mod = 998244353;
ll lpf[mxn];
unordered_map<ll,ll> mp;
vector<vector<int>> all[33];
ll n,k;
ll ans = 1;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = 1LL*re*a%mod;
        a = 1LL*a*a%mod;
        b>>=1;
    }
    return re;
}
ll inv(ll k){
    return pw(k,mod-2);
}
ll mad(ll a,ll b){
    a += b;
    if(a>=mod)a -= mod;
    return a;
}
vector<vector<ll>> mmul(vector<vector<ll>> a,vector<vector<ll>> b){
    while(b.size() != a.size())b.push_back(b.back());
    vector<vector<ll>> re(a[0].size(),vector<ll>(b[0].size(),0LL));
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[0].size();j++){
            for(int k = 0;k<b[0].size();k++){
                re[i][k] = mad(re[i][k],1LL*a[i][j]*b[j][k]%mod);
            }
        }
    }
    return re;
}
void init(ll k){
    ll sz = 1;
    ll tmp = 1;
    while(1LL*tmp*k<mxn){
        tmp *= k;
        sz++;
    }
    mp[k] = sz;
}
void solve(){
    ll a;
    cin>>a;
    unordered_map<int,int> mp2;
    while(a != 1){
        mp2[lpf[a]]++;
        a /= lpf[a];
    }
    ll re = 1;
    for(auto &i:mp2){
        ll cnt = 0,sum = 0;
        ll tt = 1;
        for(auto &j:all[mp[i.fs]][i.sc]){
            cnt = mad(cnt,j);;
            sum = mad(sum,1LL*tt*j%mod);
            tt = 1LL*tt*i.fs%mod;
        }
        re = 1LL*re*sum%mod*inv(cnt)%mod;
    }
    ans = 1LL*ans*re%mod;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    lpf[1] = 1;
    for(int i = 2;i<mxn;i++){
        if(!lpf[i]){
            primes.push_back(i);
            for(int j = i;j<mxn;j+=i){
                lpf[j] = i;
            }
        }
    }
    cin>>n>>k;
    for(auto &i:primes)init(i);
    for(int i = 1;i<33;i++){
        all[i] = vector<vector<int>>(i,vector<int>(i));
        for(int j = 0;j<i;j++){
            int iv = inv(j+1);
            for(int kk = 0;kk<=j;kk++){
                all[i][j][kk] = iv;
            }
        }
        int tk = k-1;
        auto tmp = all[i];
        while(tk){
            if(tk&1)all[i] = mmul(all[i],tmp);
            tmp = mmul(tmp,tmp);
            tk>>=1;
        }
    }
    // for(auto &i:all[9]){
    //     for(auto &j:i)cout<<j<<' ';cout<<endl;
    // }
    // cout<<mp[5];return 0;
    while(n--){
        solve();
    }
    cout<<ans;
}