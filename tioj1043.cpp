#include <bits/stdc++.h>
using namespace std;

#define ll long long


const ll mxn = 1e4+10;
ll dp[mxn];
int n;
void solve(){
    ll p;
    cin>>p;
    fill(dp,dp+p+1,0LL);
    dp[0] = 1;
    while(n--){
        ll k;
        cin>>k;
        for(int i = k;i<=p;i++){
            dp[i] += dp[i-k];
        }
    }
    cout<<dp[p]<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        if(!n)return 0;
        solve();
    }
}