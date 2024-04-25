#include <bits/stdc++.h>
using namespace std;

#define ld long double

const int mxn = 606;
vector<int> paths[mxn];
ld dp[mxn];
int n,m;
ld ans = 0;

void f(int k){
    for(int i = n-1;i>=1;i--){
        dp[i] = 0;
        if(i != k){
            for(auto nxt:paths[i])dp[i] += dp[nxt];
            dp[i] /= paths[i].size();
            dp[i] +=1;
        }
        else if(paths[i].size()>1){
            ld big = 0;
            for(auto nxt:paths[i]){
                dp[i] += dp[nxt];
                big = max(big,dp[nxt]);
            }
            dp[i] -= big;
            dp[i]  = dp[i]/(paths[i].size()-1)+1;
        }
        else return;
    }
    ans = min(ans,dp[1]);
    return;
}
int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++)dp[i] = 0;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
    }
    for(int i = n-1;i>=1;i--){
        for(auto nxt:paths[i]){
            dp[i] += dp[nxt];
        }
        dp[i] = dp[i]/paths[i].size()+1;
    }
    ans = dp[1];
    for(int i = 1;i<n;i++)f(i);
    cout<<fixed<<setprecision(10)<<ans;
}