#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    ll k = min(a,b);
    b = max(a,b);
    a = k;
    while(a>0){
        b -= (b/a)*a;
        ll k = b;
        b = a;
        a = k;
    }
    return b;
}
int main(){
    ll n;
    while(scanf("%lld",&n)!= EOF){
        if(n == 0)return 0;
        ll a = 1;
        ll b = 1;
        for(ll i =0;i<n;i++){
            scanf("%lld",&a);
            b = (a*b)/(gcd(a,b));
        }
        printf("%lld\n",b);
    }
}