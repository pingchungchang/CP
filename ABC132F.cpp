#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define fs first
#define sc second
#define ll long long

const ll mod = 1e9+7;

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
ll mad(ll a,ll b){
    a += b;
    if(a>=mod)a -= mod;
    return a;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vector<pll> v;
    ll now = 1;
    while(now<=n){
        ll r = n/(n/now);
        v.push_back({now,r-now+1});
        now = r+1;
    }
    int pref[v.size()] = {};
    for(int i = 0;i<v.size();i++){
        int l = 0,r =v.size()-1;
        while(l != r){
            int mid = (l+r+1)>>1;
            if(v[i].first+v[i].second-1<=n/v[mid].first)l = mid;
            else r = mid-1;
        }
        pref[i] = l;
    }
    // for(int i = 0;i<v.size();i++)cout<<v[i].first<<' ';cout<<endl;
    // for(auto &i:pref)cout<<i<<" ";cout<<endl;for(auto &i:pref)cout<<v[i].first<<' ';cout<<endl;
    ll dp[2][v.size()];
    bool roll = 0;
    dp[0][0] = 1;
    for(int j = 1;j<v.size();j++)dp[roll][j] = mad(dp[roll][j-1],v[j].second);
    for(int i = 2;i<=k;i++){
        roll ^= 1;
        for(int j = 0;j<v.size();j++){
            dp[roll][j] = dp[roll^1][pref[j]]*v[j].second%mod;
        }
        for(int j = 1;j<v.size();j++)dp[roll][j] = mad(dp[roll][j],dp[roll][j-1]);
    }
    ll ans = 0;
    cout<<dp[roll][v.size()-1];
}

/*
n/x = 
*/