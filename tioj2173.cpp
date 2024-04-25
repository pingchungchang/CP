#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 110;
int arr[mxn][mxn];
pii dp[mxn][mxn];
int main(){
    int n,m;
    cin>>n>>m;
    memset(arr,-1,sizeof(arr));
    for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>arr[i][j];
    for(int j = 2;j<m;j++){
        if(arr[1][j] != -1){
            if(arr[1][j-1] == -1)arr[1][j] = -1;
            else dp[1][j] = {dp[1][j-1].fs+arr[1][j],1};
        }
    }
    if(arr[1][1] == 1){
        dp[1][1] = {1,0};
    }
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=m;j++){
            dp[i][j] = {INT_MIN,0};
            if(arr[i-1][j] != -1){
                dp[i][j] = max(dp[i][j],{dp[i-1][j].fs+arr[i][j],0});
            }
            if(arr[i][j-1] != -1){
                dp[i][j] = max(dp[i][j],{dp[i][j-1].fs+arr[i][j],1});
            }
        }
    }
    bool flag = true;
    if(dp[n][m].fs <=0){
        cout<<"0\n";
        return 0;
    }
    pii now = {n,m};
    int ans = dp[n][m].fs;
    while(now.fs != 1||now.sc != 1){
        arr[now.fs][now.sc] = 0;
        if(dp[now.fs][now.sc].sc)now.sc--;
        else now.fs--;
    }
    arr[1][1] = 0;
    /*
    cout<<ans<<endl;
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=m;j++)cout<<arr[i][j]<<' ';cout<<endl;
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++)dp[i][j] = {0,0};
    }
    */

    for(int j = 2;j<m;j++){
        if(arr[1][j] != -1){
            if(arr[1][j-1] == -1)arr[1][j] = -1;
            else dp[1][j] = {dp[1][j-1].fs+arr[1][j],0};
        }
    }
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=m;j++){
            dp[i][j] = {INT_MIN,0};
            if(arr[i-1][j] != -1){
                dp[i][j] = max(dp[i][j],{dp[i-1][j].fs+arr[i][j],1});
            }
            if(arr[i][j-1] != -1){
                dp[i][j] = max(dp[i][j],{dp[i][j-1].fs+arr[i][j],0});
            }
        }
    }
    if(flag)cout<<ans+dp[n][m].fs;
}
