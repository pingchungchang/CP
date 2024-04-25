#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    ll ans = 1e18;
    for(ll i = 1;i<=a;){
        ll r = a/(a/i);
        ans = min(ans,(a+i-1)/i+i-1+(b+i-1)/i);
        i = r;
        ans = min(ans,(a+i-1)/i+i-1+(b+i-1)/i);
        i = r+1;
    }
    for(ll i = 1;i<=b;){
        ll r = b/(b/i);
        ans = min(ans,(a+i-1)/i+i-1+(b+i-1)/i);
        // cout<<i<<":"<<(a+i-1)/i+i-1+(b+i-1)/i<<endl;
        i = r;
        ans = min(ans,(a+i-1)/i+i-1+(b+i-1)/i);
        i = r+1;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}