#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9+7;

ll pw(ll a,ll b){
    ll re =1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
ll inv(ll a){
    return pw(a,mod-2);
}

int main(){
    ll n,m;
    cin>>n>>m;
    ll total = 0;
    ll a= n;
    for(ll  i = 0;i<n;i++){
        total += pw(m,__gcd(i,a));
        if(total>=mod)total -= mod;
    }
    cout<<total*inv(n)%mod;
}