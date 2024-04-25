#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    while(cin>>n>>x){
        vector<vector<int>> m(n+1,vector<int>(n+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                int k;
                cin>>k;
                m[i][j] = k;
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+m[i][j];
            }
        }
        for(int i = 0;i<x;i++){
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1]<<"\n";
        }
    }
}