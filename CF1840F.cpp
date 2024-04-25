#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int inf = 1e9;

void solve(){
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	int dp[2][n+2][m+2];
	memset(dp,0,sizeof(dp));
	vector<pair<int,int>> op[n+m+r*2];
	for(int i = 0;i<r;i++){
		int t,d,c;
		cin>>t>>d>>c;
		t = min(t,n+m+r*2-1);
		c++;
		op[t].push_back(make_pair(d,c));
	}
	bool roll = 0;
	dp[roll][1][1] = 1;
	for(int step = 1;step<n+m+r*2;step++){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		for(int i = 1;i<=n+1;i++)for(int j = 1;j<=m+1;j++){
			if(dp[roll^1][i][j]||dp[roll^1][i-1][j]||dp[roll^1][i][j-1])dp[roll][i][j] = true;
		}
		for(auto &i:op[step]){
			//cout<<i.fs<<','<<i.sc<<',';
			if(i.fs == 1){
				for(int j = 0;j<=m+1;j++)dp[roll][i.sc][j] = 0;
			}
			else for(int j = 0;j<=n+1;j++)dp[roll][j][i.sc] = 0;
		}
		/*
		cout<<'\n';
		for(int i = 1;i<=n+1;i++){
			for(int j = 1;j<=m+1;j++)cout<<dp[roll][i][j];
			cout<<'\n';
		}
		cout<<'\n';

	   */
		if(dp[roll][n+1][m+1]){
			cout<<step<<'\n';
			return;
		}
	}
	cout<<"-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
