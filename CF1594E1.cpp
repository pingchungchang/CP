#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    ll k =1;
    k<<=n;
    k -=2;
    //cout<<k<<endl;
    ll now = 6;
    ll base = 4;
    ll x = 4;
    while(k>0){
        if(k&1)now *= x;
        x*=x;
        k>>=1;
        x = x%mod;
        now = now%mod;
    }
    cout<<now;
}
