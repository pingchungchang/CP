#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll x1,y1,x2,y2,r;
    while(scanf("%lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&r)!= EOF){
        y2-=y1;
        x2-=x1;
        x2=abs(x2);
        y2=abs(y2);
        if(y2>r-x2)printf("alive\n");
        else printf("die\n");
        // (0,0) (r,0) (0,r)
    }
}