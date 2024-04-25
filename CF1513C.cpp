#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mxn = 2e5+10;
ll dp[10][mxn][10];
const ll mod = 1e9+7;
void solve(){
	ll n,m;
	cin>>n>>m;
	string s = to_string(n);
	ll ans = 0;
	for(auto i:s){
		int tmp = i-'0';
		for(int j = 0;j<=9;j++)ans += dp[tmp][m][j];
		ans %= mod;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	io
	int t;
	memset(dp,0LL,sizeof(dp));
	for(int i = 0;i<=9;i++)for(int j = 0;j<mxn;j++)for(int k = 0;k<=9;k++)dp[i][j][k] = 0;
	for(int i = 0;i<=9;i++)dp[i][0][i] = 1;
	for(int i = 0;i<=9;i++){
		for(int j = 1;j<mxn;j++){
			dp[i][j][0] = dp[i][j-1][9];
			dp[i][j][1] = dp[i][j-1][0]+dp[i][j-1][9];
			for(int k = 2;k<=9;k++){
				dp[i][j][k] = dp[i][j-1][k-1];
			}
			for(int k = 0;k<=9;k++)dp[i][j][k]%=mod;
		}
	}
//	for(int i = 0;i<=9;i++)cout<<dp[9][1][i]<<' ';cout<<endl;
	cin>>t;
	while(t--)solve();
}

