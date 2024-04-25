#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll dp[55][55];
void solve(){
    vector<ll> v(27,0);
    string s;
    cin>>s;
    for(auto i:s)v[i-'a']++;
    bool flag = false;
    ll ans = 1;
    ll total = 0;
    for(auto &i:v){
        if(i%2 == 1&&flag == true){
            cout<<0<<"\n";
            return;
        }
        else if(i%2 == 1)flag = true;
        i>>=1;
        total += i;
    }
    for(auto i:v){
        ans *= dp[total][i];
        total -= i;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,0LL,sizeof(dp));
    for(ll i = 0;i<=50;i++){
        dp[0][i] = 0;
        dp[i][0] = 1;
    }
    for(ll i = 1;i<=50;i++){
        for(ll j= 1;j<=i;j++)dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
    }
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
