#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(auto &i:arr)cin>>i;
    for(auto &i:brr)cin>>i;
    int dp[n];
    int same[n];
    int pre[n];
    memset(same,-1,sizeof(same));
    memset(dp,-1,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[i] == brr[j])same[i] = j;
        }
    }
    for(int i = 0;i<n;i++){
        dp[i] = 0;
        if(same[i] != -1){
            dp[i] = 1;
        }
        for(int j = 0;j<i;j++){
            if(same[j]<same[i]&&arr[j]>arr[i]){
                if(dp[i]<dp[j]+1){
                    pre[i] = j;
                    dp[i] = dp[j]+1;
                }
            }
        }
    }
    vector<int> ans;
    pair<int,int> big = {0,0};
    for(int i =0;i<n;i++){
        big = max(big,{dp[i],i});
    }
    int now = big.second;
    while(now != -1&&dp[now])ans.push_back(arr[now]),now = pre[now];
    reverse(ans.begin(),ans.end());
    for(auto &i:ans)cout<<i<<' ';cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}