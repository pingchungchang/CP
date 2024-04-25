#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    unordered_map<int,char> m;
    m[5] = 'A';
    m[7] = 'B';
    m[2] = 'C';
    m[13] = 'D';
    m[8] = 'E';
    m[12] = 'F';
    while(scanf("%d\n",&n)!= EOF){
        for(ll i =0;i<n;i++){
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            printf("%c",m[8*a+4*b+2*c+d]);
            scanf("\n");
        }
        printf("\n");
    }
}