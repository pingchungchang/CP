#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n){
    ll ans = 0;
    while(n != 1LL){
        n = (n%2?3*n+1:n/2);
        ans++;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    while(cin>>n){
        if(n == -1)return 0;
        solve(n);
    }
}
