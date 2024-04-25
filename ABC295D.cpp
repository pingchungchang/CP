#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[1<<10];

int main(){
    string s;
    cin>>s;
    ll ans = 0;
    int now = 0;
    dp[now] = 1;
    for(auto &i:s){
        now ^= (1<<(i-'0'));
        ans += dp[now];
        dp[now]++;
    }
    cout<<ans;
}