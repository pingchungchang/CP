#include <bits/stdc++.h>
using namespace std;

int mod = 1e4+7;
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int now = 1;
    a = a%mod;
    while(b>0){
        if(b&1){
            now *=a;
            now = now%mod;
        }
        b>>=1;
        a=a*a;
        a = a%mod;
    }
    cout<<now;
}