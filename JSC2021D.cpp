#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod,n;
const ll MOD = 1e9+7;
ll pw(ll a,ll b){
    ll re= 1;
    while(b){
        if(b&1)re = re*a%MOD;
        b>>=1;
        a = a*a%MOD;
    }
    return re;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>mod;
    cout<<(mod-1)*pw(mod-2,n-1)%MOD;
}