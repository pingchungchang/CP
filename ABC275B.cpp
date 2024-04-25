#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;

int main(){
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    a %= mod,b%=mod,c%=mod,d%=mod,e%=mod,f%=mod;
    cout<<(a*b%mod*c%mod-d*e%mod*f%mod+mod)%mod;
}
