#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t,n;
    cin>>t>>n;
    int dp[t+1] = {0};
    string ans;
    float avg = 0;
    pair<int,int> jobs[n];
    for(int i =0;i<n;i++){
        float a,b;
        string s;
        cin>>s>>a>>b;
        if(avg<a/b){
            ans = s;
            avg = a/b;
        }
        jobs[i] = make_pair((int)a,(int)b);
    }
    for(int i =0;i<n;i++){
        for(int j =t;j>=jobs[i].second;j--){
            dp[j] = max(dp[j-jobs[i].second]+jobs[i].first,dp[j]);
        }
    }
    cout<<dp[t-1]<<'\n'<<ans;
}