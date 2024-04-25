#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    ll ans = (abs(a)+abs(b))*x;
    ans = min(ans,abs(a)*y+x*abs(b-a));
    ans = min(ans,abs(b)*y+x*abs(a-b));
    cout<<ans<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
