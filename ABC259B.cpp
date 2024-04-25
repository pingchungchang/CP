#include <bits/stdc++.h>
using namespace std;

#define ld long double
const ld PI = acos(-1);

int main(){
    ld a,b,d;
    cin>>a>>b>>d;
    d = d/180*PI;
    ld ta = a*cos(d)-b*sin(d);
    ld tb = a*sin(d)+b*cos(d);
    cout<<fixed<<setprecision(10)<<ta<<' '<<tb;
}