#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 110;
ll dp[mxn][mxn];
const ll inf = 1e18;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k,d;
    cin>>n>>k>>d;
    for(auto &i:dp)for(auto &j:i)j = -inf;
    ll arr[n];
    dp[0][0] = 0;
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<n;i++){
        for(int j = k;j>=1;j--){
            for(int l = 0;l<d;l++){
                dp[j][l] = max(dp[j][l],dp[j-1][(l+d-arr[i]%d)%d]+arr[i]);
            }
        }
        // for(int j = 0;j<=k;j++){
        //     for(int l = 0;l<d;l++)cout<<dp[j][l]<<' ';
        //     cout<<endl;
        // }
    }
    if(dp[k][0]<0)cout<<-1;
    else cout<<dp[k][0];
}