#include <bits/stdc++.h>
using namespace std;
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
int main(){
    ll n;
    cin>>n;
    ll total = 0;
    total += pw(2LL,n*n)+pw(2LL,(n*n+3)/4)*2LL+pw(2LL,(n*n+1)/2);
    total %= mod;
    cout<<total*inv(4LL)%mod;
}