#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    ll twos = 2;
    ll ans = 1;
    while(n!=0){
        if(n&1)ans *= twos;
        twos*=twos;
        n>>=1;
        ans = ans%mod;
        twos = twos%mod;
    }
    cout<<ans;
}
