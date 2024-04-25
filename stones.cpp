#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int dp[k+1] = {0};
    int stones[n];
    for(int i =0;i<n;i++){
        cin>>stones[i];
        dp[stones[i]] = 1;
    }
    sort(stones,stones+n);
    for(int i =0;i<stones[0];i++)dp[i] = -1;
    for(int i =stones[0]+1;i<=k;i++){
        for(int j =0;j<n;j++){
            if(i>stones[j]){
                if(dp[i-stones[j]] == -1)dp[i] = 1;
            }
        }
        if(dp[i]!=1)dp[i] = -1;
    }
    if(dp[k] == -1)cout<<"Second";
    else cout<<"First";
}
