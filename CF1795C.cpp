#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 2e5+10;
ll a[mxn],b[mxn];
ll ans[mxn];
ll dif[mxn];

void solve(){
    int n;
    cin>>n;
    fill(a,a+n+1,0LL);
    fill(b,b+n+1,0LL);
    fill(ans,ans+n+1,0LL);
    fill(dif,dif+n+1,0LL);
    for(int i = 1;i<=n;i++)cin>>b[i];
    for(int i = 1;i<=n;i++)cin>>a[i];
    for(int i = 1;i<=n;i++)a[i] += a[i-1];
    for(int i = 1;i<=n;i++){
        auto pos = upper_bound(a+i,a+n+1,b[i]+a[i-1])-a;
        dif[i]++;
        dif[pos]--;
        if(pos>=i)ans[pos] += b[i]-(a[pos-1]-a[i-1]);
    }
    for(int i = 1;i<=n;i++)dif[i] +=dif[i-1];
    for(int i = 1;i<=n;i++)cout<<ans[i] + dif[i]*(a[i]-a[i-1])<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}