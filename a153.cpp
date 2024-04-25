#include <bits/stdc++.h>
using namespace std;

#define ld long double

ld eps = 1e-8;

ld f(ld x){
    return 2-exp(x);
}
int main(){
    ld l = 0;
    ld r = 2;
    while(r-l>eps){
        ld mid = (l+r)/2;
        if(f(mid)*f(r)<0)l = mid;
        else r = mid;
    }
    cout<<r;
}
