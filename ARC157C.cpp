#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 998244353;
const ll mxn = 2020;

ll dp[mxn][mxn][3];//ways,cnt,ans

ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}

void solve(){
	ll n,m;
	cin>>n>>m;
	string arr[n+1];
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] = "#"+arr[i];
	}
	memset(dp,0,sizeof(dp));
	dp[1][1][0] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(i == 1&&j == 1)continue;
			dp[i][j][0] = mad(dp[i-1][j][0],dp[i][j-1][0]);
			dp[i][j][1] = mad(dp[i-1][j][1],dp[i][j-1][1]);
			dp[i][j][2] = mad(dp[i-1][j][2],dp[i][j-1][2]);
			if(arr[i][j] == 'Y'&&arr[i][j-1] == 'Y'){
				dp[i][j][1] = mad(dp[i][j][1],dp[i][j-1][0]);
				dp[i][j][2] = mad(dp[i][j][2],mad(2LL*dp[i][j-1][1]%mod,dp[i][j-1][0]));
			}
			if(arr[i][j] == 'Y'&&arr[i-1][j] == 'Y'){
				dp[i][j][1] = mad(dp[i][j][1],dp[i-1][j][0]);
				dp[i][j][2] = mad(dp[i][j][2],mad(2LL*dp[i-1][j][1]%mod,dp[i-1][j][0]));
			}
		}
	}
	cout<<dp[n][m][2];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
