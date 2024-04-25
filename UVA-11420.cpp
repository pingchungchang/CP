#include <bits/stdc++.h>
using namespace std;

int main(){
    long long dp[66][66];
    long long sums[66][66];
    memset(dp, -1, sizeof(dp[0][0]) * 66 * 66);
    memset(sums,-1,sizeof(sums[0][0])*66*66);
    int n,m;
    dp[0][0] = 0;
    sums[0][0] = 0;
    dp[0][1] = 1;
    sums[0][1] = 1;
    dp[0][2] =2;
    sums[0][2] = 3;
    for(int i = 0;i<66;i++){
        dp[i][i] = 1;
        sums[i][i] = 1;
    }
    while(scanf("%d %d",&n,&m) != EOF){
        if(m<0&&n<0)return 0;
        if(dp[m][n] == -1){
            for(int i = 0;i<=m;i++){
                for(int j = 0;j<=n;j++){
                    if(dp[i][j] == -1){
                        if(i>j) {
                            dp[i][j] = 0;
                            sums[i][j] = 0;
                        }
                        else if(i == 0){
                            dp[i][j] = dp[i][j-1]+dp[i][j-2];
                        }
                        else{
                            dp[i][j] = sums[i][j-2]+dp[i-1][j-1];
                            sums[i][j] = sums[i][j-1]+dp[i][j];
                        }
                        // cout<<i<<' '<<j<<' '<<dp[i][j]<<',';
                    }
                }
                // cout<<endl;
            }
        }
        printf("%lld\n",dp[m][n]);
        scanf("\n");
    }
}