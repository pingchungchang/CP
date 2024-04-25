#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;


int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> v1(n),v2(m),dp1(n,0LL),dp2(m,0LL);
    for(ll i = 0;i<n;i++){
        cin>>v1[i];
    }
    for(ll i = 0;i<m;i++)cin>>v2[i];
    for(ll i = 1;i<n;i++){
        dp1[i] = dp1[i-1]+(v1[i]-v1[i-1])*i;
        dp1[i]%= mod;
    }
    for(ll i = 1;i<m;i++){
        dp2[i] = dp2[i-1]+(v2[i]-v2[i-1])*i;
        dp2[i]%= mod;
    }
    ll s1 = 0,s2 = 0;
    for(auto i:dp1)s1 = (s1+i)%mod;
    for(auto i:dp2)s2 = (s2+i)%mod;
    cout<<s1*s2%mod;
}
