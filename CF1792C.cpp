#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int cnt = 0;
    int pos[n+1] = {};
    for(int i = 0;i<n;i++)pos[arr[i]] = i;
    int dp[n+1] = {};
    for(int i = 0;i<n;i++){
        dp[arr[i]] = 1;
        if(arr[i] == 1)continue;
        if(pos[arr[i]-1]<i)dp[arr[i]] = dp[arr[i]-1]+1;
    }
    for(int i = 1;i<=n;i++){
        if(i<n/2)continue;
        int l = i-dp[i]+1;
        if(n&1)cnt = max(cnt,min(i-(n+1)/2+1,(n+1)/2-l+1));
        else cnt = max(cnt,min(i-n/2,n/2-l+1));
    }
    // cout<<cnt<<":";
    if(n&1){
        cout<<(n-cnt*2+1)/2<<'\n';
    }
    else cout<<(n-cnt*2)/2<<'\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}