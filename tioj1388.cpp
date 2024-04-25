#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 110;
ll dp[mxn][mxn];
ll arr[mxn];
int n;


ll f(ll l,ll r){
	if(l == r)return dp[l][r] = arr[l];
	dp[l][r] = 0;
	for(int i = l;i<r;i++){
		if((r-l+1)&1)dp[l][r] = max(dp[l][r],f(l,i)*f(i+1,r));
		else dp[l][r] = max(dp[l][r],f(l,i)+f(i+1,r));
	}
	return dp[l][r];
}

void solve(){
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j+i-1<=n;j++){
			int l = j,r = i+j-1;
			if(l == r)dp[l][r] = arr[l];
			else{
				for(int k = l;k<r;k++){
					if(i&1)dp[l][r] = max(dp[l][r],dp[l][k]*dp[k+1][r]);
					else dp[l][r] = max(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
	}
	cout<<dp[1][n]<<'\n';
	for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++)dp[i][j] = -1;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp,-1,sizeof(dp));
	while(cin>>n)solve();
}
