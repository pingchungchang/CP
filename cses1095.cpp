#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9+7;
ll pw(ll a,ll b){
    ll now = 1;
    ll tmp = a;
    while(b != 0){
        if((b&1))now *= tmp;
        tmp = tmp*tmp%mod;
        now = now%mod;
        b>>=1;
    }
    return now;
}
int main(){
    ll q;
    cin>>q;
    for(ll i = 0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        cout<<pw(a,b)<<'\n';
    }
}
