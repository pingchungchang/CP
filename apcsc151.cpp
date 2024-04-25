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
#define int ll
const int inf = 1e11+10;
main(){
	io
	int n,m;
	int d;
	cin>>n>>m;
	cin>>d;
	int dp[n+1][n+1];
	memset(dp,inf,sizeof(dp));;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		dp[a][b] = min(dp[a][b],c);
		dp[b][a] = min(dp[b][a],c);
	}
	for(int i = 1;i<=n;i++)dp[i][i] = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=n;k++){
				dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
//			cout<<dp[i][j]<<' ';
			if(dp[i][j]<=d)cout<<j<<' ';
		}
		cout<<'\n';
	}
	return 0;
}

