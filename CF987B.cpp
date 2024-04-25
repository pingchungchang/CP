#include <bits/stdc++.h>
using namespace std;

#define ld long double
const ld eps = 1e-6;
int main(){
    ld a,b;
    cin>>a>>b;
    if(abs(a*log(b)-b*log(a)) <=eps){
        cout<<"=";
    }
    else if(a*log(b)>b*log(a)){
        cout<<"<";
    }
    else cout<<">";

}