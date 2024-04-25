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
const int inf = 505;
int n,m;
void solve(){
	int dp[n+1][n+1] = {};
	for(auto &i:dp)for(auto &j:i)j = inf;
	while(m--){
		int a,b;
		cin>>a>>b;
		dp[a][b] = 1;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=n;k++){
				dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
	int ans = inf;
	for(int i = 1;i<=n;i++)ans = min(ans,dp[i][i]);
	if(ans >=inf)cout<<0<<"\n";
	else cout<<ans<<'\n';
	return;
}
int main(){
	io
	while(cin>>n>>m){
		if(n == 0&&m == 0)return 0;
		solve();
	}
	
}
