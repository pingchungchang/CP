#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

ll a,b;
ld f(ll k){
    return (ld)k*b+a/sqrt(1+k);
}
int main(){
    cin>>a>>b;
    ld l = 0,r = 1e18;
    while(l != r){
        ll mid = (l+r+1)/2;
        if(f(mid)>f(mid-1))r = mid-1;
        else l = mid;
    }
    cout<<fixed<<setprecision(10)<<f(l);
}