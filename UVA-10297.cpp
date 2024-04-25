#include <bits/stdc++.h>
using namespace std;

int main(){
    double D,V;
    while(cin>>D>>V){
        if(D == 0&&V==0) return 0;
        //cout<<D*D*D<<' '<<3*V/3.14159<<endl;
        double d = pow(D*D*D-(6*V)/3.141592653589793238462643,0.333333333333333333333);
        cout<<fixed<<setprecision(3)<<d<<endl;
    }
}
