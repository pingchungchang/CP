#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b;
    scanf("%lld %lld",&a,&b);
    if(a&1 == 1) a++;
    if(b&1==1) b--;
    printf("%lld",(a+b)*((b-a)/2+1)/2);
}