#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
int main(){
    int n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    ll dp[m] = {0};
    dp[0] = 1;
    for(int i =0;i<n;i++){
        string s;
        cin>>s;
        if(s[0] =='#')dp[0] = 0;
        for(int j =1;j<m;j++){
            if(s[j] == '#')dp[j] = 0;
            else dp[j] = (dp[j-1]+dp[j])%mod;
        }
    }
    cout<<dp[m-1];
}
