#include <bits/stdc++.h>
using namespace std;

const int mxn = 1999999;
int dp[mxn];

int main(){
    dp[1] = 1;
    for(int i =2;i<mxn;i++){
        int cnt = 0;
        int now =i;
        while(now){
            cnt += (now%10 != 0);
            now/=10;
        }
        if(cnt==1)dp[i]++;
        dp[i] += dp[i-1];
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        cout<<dp[k]<<'\n';
    }
    return 0;
}