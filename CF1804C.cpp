#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,x,p;
    cin>>n>>x>>p;
    ll tar = (n-x)%n;
    for(ll i = 1;i<=min(n*2,p);i++){
        if(i*(i+1)/2%n == tar){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}