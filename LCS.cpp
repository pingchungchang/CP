#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
int dp[3030][3030];
pii pre[3030][3030];
int main(){
    string s,t;
    cin>>s>>t;
    for(int i = 0;i<s.size();i++){
        for(int j= 0;j<t.size();j++){
            dp[i+1][j+1] = dp[i][j+1];
            pre[i+1][j+1] = {i,j+1};
            if(dp[i+1][j] > dp[i+1][j+1]){
                pre[i+1][j+1] = {i+1,j};
                dp[i+1][j+1] = dp[i+1][j];
            }
            if(s[i] == t[j]){
                if(dp[i][j]+1>=dp[i+1][j+1]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    pre[i+1][j+1] = {i,j};
                }
            }
        }
    }
    string ans = "";
    pii now = {s.size(),t.size()};
    while(now.fs != 0){
        // cout<<now.fs<<' '<<now.sc<<endl;
        if(pre[now.fs][now.sc].fs != now.fs&&now.sc != pre[now.fs][now.sc].sc)ans += s[now.fs-1];
        now = pre[now.fs][now.sc];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}