#include <bits/stdc++.h>
using namespace std;

int main(){
    double a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    double x = (b2-b1)/(a1-a2);
    double y = (a1*b2-a2*b1)/(a1-a2);
    if(x == -0)x = 0;
    if(y == -0)y = 0;
    cout<<fixed<<setprecision(2)<<x<<'\n'<<y;
}
