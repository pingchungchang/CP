#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll x,y,z;
    z = c,y = b,x = a+b*(ll)1e9;
    cout<<x<<' '<<y<<' '<<z<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
