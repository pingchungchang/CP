#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int now = 1,pre =0;
    vector<vector<vector<bool>>> dp(2,vector<vector<bool>>(n,vector<bool>(m,false)));
    dp[now][x1][y1] = true;
    cin>>k;
    for(int asd=0;asd<k;asd++){
        int t;
        cin>>t;
        swap(now,pre);
        dp[now] = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dp[pre][(i+t)%n][j])dp[now][i][j] = true;
                else if(dp[pre][(i+n-t%n)%n][j])dp[now][i][j] = true;
                else if(dp[pre][i][(j+t)%m])dp[now][i][j] = true;
                else if(dp[pre][i][(j+m-t%m)%m])dp[now][i][j] = true;
            }
        }
    }
    if(dp[now][x2][y2])cout<<"YES";
    else cout<<"NO";
}
