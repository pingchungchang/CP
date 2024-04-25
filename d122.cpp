#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    while(cin>>n){
        long long k = 5;
        long long ans  =0;
        while(k<=n){
            ans += n/k;
            k*=5;
        }
        printf("%lld\n",ans);
    }
}