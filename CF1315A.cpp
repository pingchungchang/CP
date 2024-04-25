#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    int ans = max({a*y,a*(b-1-y),x*b,(a-1-x)*b});
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}