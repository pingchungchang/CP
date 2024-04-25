#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isprime(ll n){
    ll j = sqrt(n);
    if(n == j*j)return false;
    for(ll i =2;i<=j;i++){
        if(n%i == 0)return false;
    }
    return true;
}
int main(){
    ll n;
    while(scanf("%lld",&n)!=EOF){
        string s;
        bool prime = isprime(n);
        ll np = n;
        while(np>0){
            s += (char)('0'+np%10);
            np = np/10;
        }
        ll nr = stoi(s);
        bool rprime = isprime(nr);
        if(rprime&&prime&&nr!=n)printf("%lld is emirp.\n",n);
        else if(prime)printf("%lld is prime.\n",n);
        else printf("%lld is not prime.\n",n);
    }
}