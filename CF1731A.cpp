#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n;
    cin>>n;
    ll total = 1;
    for(int i = 0;i<n;i++){
        ll k;
        cin>>k;
        total *= k;
    }
    cout<<2022LL*(total+n-1)<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}