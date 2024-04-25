#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll inf = 1e18;
int main(){
	io
	ll n,m;
	cin>>n>>m;
	ll dp[m+1];
	fill(dp,dp+m+1,-inf);
	ll arr[n];
	dp[0] = 0;
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++){
		for(int k = min(m,(ll)i+1);k>=1;k--){
			dp[k] = max(dp[k],dp[k-1]+k*arr[i]);
		}
//		for(int j = 0;j<=m;j++)cout<<dp[j]<<' ';cout<<endl;
	}
	cout<<dp[m];
}

