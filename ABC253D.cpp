#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll q(ll n,ll a){
    return (a+n/a*a)*(n/a)/2;
}
ll gcd(ll a,ll b){
    if(a <b)swap(a,b);
    while(b != 0){
        a %= b;
        swap(a,b);
    }
    return a;
}
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll g = a*b/gcd(a,b);
    cout<<n*(n+1)/2-(q(n,a)+q(n,b)-q(n,g));
}
