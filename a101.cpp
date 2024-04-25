#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int sum = 0;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
        sum += v[i];
    }
    vector<int> dp(sum/2+1,0);
    dp[0] = 0;
    for(int i = 0;i<n;i++){
        for(int j = dp.size()-1;j>=v[i];j--){
            dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
        }
    }
    cout<<abs(sum-2*dp[dp.size()-1])<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
