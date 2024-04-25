#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll A[n],B[n];
    for(int i = 0;i<n;i++)cin>>A[i]>>B[i];
    ll G = B[0];
    ll L = A[0]*B[0];
    ll ans = 1;
    for(int i = 0;i<n;i++){
        G = G*B[i]/__gcd(G,B[i]);
        L = __gcd(L,A[i]*B[i]);
        if(L%G != 0){
            ans++;
            G = B[i];
            L = A[i]*B[i];
        }
    }
    cout<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}