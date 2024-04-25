#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
const ll mxn= 606;
ld a[mxn],b[mxn];
ld buf[mxn];
void mult(ld a[],ld b[],ld p[]){
    for(auto &i:buf)i = 0.0;
    for(int i = 0;i<mxn;i++){
        for(int j =0;j+i<mxn;j++){
            buf[i+j] += a[i]*b[j];
        }
    }
    for(int i= 0;i<mxn;i++)p[i] = buf[i];
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 1;i<=6;i++)a[i] = b[i] = 1;
    int n,s,e;
    cin>>n>>s>>e;
    n--;
    while(n){
        if(n&1)mult(a,b,a);
        mult(b,b,b);
        n>>=1;
    }
    ld ans = 0;
    ld total = 0;
    for(auto &i:a)total += i;
    for(int i = s;i<=e;i++)ans += a[i];
    cout<<fixed<<setprecision(6)<<ans/total;
}
/*
ll a[mxn],b[mxn];
*/