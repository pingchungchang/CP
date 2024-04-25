#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535
int main(){
    double x;
    double n;
    while(cin>>n){
        if(n>1) printf("FAIL!\n");
        else{
            x = asin(n);
            if(x>1){
                printf("FAIL!\n");
                continue;
            }
            x = acos(x);
            x*=180;
            x/=PI;
            cout<<fixed<<setprecision(2)<<x<<endl;
        }
    }
}