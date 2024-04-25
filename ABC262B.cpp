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
int main(){
	io
	int n,m;
	cin>>n>>m;
	int dp[n+1][n+1] = {};
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		dp[a][b] = dp[b][a] = 1;
	}
	int ans= 0;
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			for(int k = j+1;k<=n;k++){
				if(dp[i][j] == 1&&dp[j][k] == 1&&dp[k][i] == 1)ans++;
			}
		}
	}
	cout<<ans;
}

