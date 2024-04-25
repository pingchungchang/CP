#include <bits/stdc++.h>
using namespace std;


unordered_map<int,vector<int>> paths;
int n;
int finddepth(int* dp,int now){
    if(dp[now] == -1)return 0;
    else if(dp[now]!=0)return dp[now];
    else{
        for(int i =0;i<paths[now].size();i++){
            dp[now] = max(dp[now],1+finddepth(dp,paths[now][i]));
        }
        return dp[now];
    }
}
int main(){
    int m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i =0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
    }
    int ans = 0;
    int dp[n+1] = {0};
    for(int i =1;i<=n;i++){
        if(paths.count(i) == 0){
            dp[i] = -1;
        }
        else{
            ans = max(ans,finddepth((int*)dp,i));
        }
    }
    cout<<ans;
}
