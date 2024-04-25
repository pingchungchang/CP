#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll k,x,mod;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a =a *a%mod;
        b>>=1;
    }
    return re;
}
ll f(ll x){
    if(x == 1)return 1;
    ll re = f(x/2)*(pw(k,x/2)+1)%mod;
    if(x&1)re = (re*k%mod+1)%mod;
    return re;
}

int main(){
    cin>>k>>x>>mod;
    cout<<f(x);
}