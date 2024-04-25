#include <bits/stdc++.h>
using namespace std;

const int mxn = 1010;
int arr[mxn];
int dp[mxn][mxn];
int f(int l,int r){
    if(dp[l][r] != -1)return dp[l][r];
    dp[l][r] = 0;
    if(l+1 == r){
        if(arr[l] == arr[r])dp[l][r] = 1;
    }
    else{
        for(int i = l+1;i<=r;i+=2){
            dp[l][r] = max(dp[l][r],f(l+1,i)+f(i+1,r)+(arr[l] == arr[i]));
        }
    }
    return dp[l][r];
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++)dp[i][j] = -1;
    }
    cout<<f(1,n)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}