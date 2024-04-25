#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    k-=2;
    if(k <= -1||m<n-1||n*(n-1)/2<m){
        cout<<"NO\n";
        return;
    }
    if(n == 1){
        cout<<"YES\n";
        return;
    }
    if(k <= 0){
        cout<<"NO\n";
        return;
    }
    if(n == 2){
        cout<<"YES\n";
        return;
    }
    if(n*(n-1)/2 == m){
        cout<<"YES\n";
        return;
    }
    if(k <2){
        cout<<"NO\n";
        return;
    }
    else cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
