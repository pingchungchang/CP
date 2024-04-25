#include <bits/stdc++.h>
using namespace std;

#define ld long double
const ld PI = acos(-1);
const ld eps = 1e-9;
const ld sixty = PI/3;
int a,b;

bool f(ld k){
    return b*tan(k)+b/cos(k)*sin(sixty-k)<=a;
}
ld calc(ld k){
    return b/cos(k);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b;
    if(a<b)swap(a,b);
    ld l = 0,r = PI/180*30;
    while(max(calc(r)-calc(l),(calc(r)-calc(l))/calc(r))>eps/2){
        ld mid = (l+r)/2;
        if(f(mid))l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(10)<<calc(l);
}