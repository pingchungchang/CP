#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(a<x)c-=x-a;
    if(c<0){
        cout<<"NO\n";
        return;
    }
    if(b+c>=y)cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
