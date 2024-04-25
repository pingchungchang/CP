#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    ll lcm = 10001;
    for(ll i = max(a,b);i<=10000;i++){
        if(i %a==0&&i%b==0){
            lcm = i;
            break;
        }
    }
    ll k = ((1+c/a)*(c/a)/2*a+(1+c/b)*(c/b)/2*b-(1+c/lcm)*(c/lcm)/2*lcm)%26;
    if(k == 0){
        printf("Z");
    }
    else printf("%c",'A'-1+k);
}