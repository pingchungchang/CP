#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,k;
    cin>>n>>k;
    if(k%2 == 0){
        if(n&1)cout<<"NO\n";
        else cout<<"YES\n";
        return;
    }
    else{
        if(n>=k&&!((n-k)&1))cout<<"YES\n";
        else if(n%2 == 0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}