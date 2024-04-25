#include <bits/stdc++.h>
using namespace std;

#define ld long double
const ld PI = acos(-1);
ld a,b,d;
bool f(ld theta){
    if(b>a/tan(theta)){
        ld area = (b+b-a/tan(theta))*a/2;
        area *= a;
        if(area>=d)return true;
        else return false;
    }
    else{
        ld area = b*b*tan(theta)/2;
        area *= a;
        if(area>=d)return true;
        else return false;
    }
}
int main(){
    ld l = 0,r = 90;
    cin>>a>>b>>d;
    for(int i = 0;i<64&&l<r;i++){
        // cout<<l<<' '<<r<<endl;
        ld mid = (l+r)/2;
        if(f(mid/180*PI))r = mid;
        else l = mid;
    }
    cout<<fixed<<setprecision(10)<<90-l;
}