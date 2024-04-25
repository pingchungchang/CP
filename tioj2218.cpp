#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 505;
ll dp[mxn][mxn];
ll ans[mxn][mxn];
const ll inf = 1e9;
ll arr[mxn];
ll f(ll l,ll r){
    cout<<l<<' '<<r<<endl;
    if(dp[l][r])return dp[l][r];
    if(l == r)return dp[l][r] = -inf;
    if(r == l+1){
        if(__gcd(arr[l],arr[r]) == 1)return dp[l][r] = -inf;
        else return dp[l][r] = __gcd(arr[l],arr[r]);
    }
    if(r == l+2){
        if(__gcd(arr[l],arr[l+1]) != 1&&__gcd(arr[l+1],arr[l+2]) != 1)return dp[l][r] = __gcd(arr[l],arr[l+1])+__gcd(arr[l+1],arr[r]);
        else return dp[l][r] = -inf;
    }
    dp[l][r] = -inf;
    for(int i = l;i<r;i++){
        dp[l][r] = max(f(l,i)+f(i+1,r),dp[l][r]);
    }
    return dp[l][r];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)cin>>arr[i];
    cout<<f(0,n-1);
}