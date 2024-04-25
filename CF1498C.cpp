#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mod = 1e9+7;
vector<vector<ll>> dp;
int n,k;

ll f(ll a,ll b){
//	cout<<a<<' '<<b<<'\n';
	if(b>n||b<=0)return 1;
	else if(b == 0){
		dp[a][b] = 1;
		return dp[a][b];
	}
	else if(dp[a][b] != -1)return dp[a][b];
	else if(a == 1){
		dp[a][b] = 1;
		return 1LL;
	}
	dp[a][b] = (f(a,b-1)+f(a-1,n-b))%mod;
//	cout<<a<<' '<<b<<' '<<dp[a][b]<<',';
	return dp[a][b];
}
void solve(){
	cin>>n>>k;
	dp = vector<vector<ll>>(k+1,vector<ll>(n+1,-1LL));
	cout<<f(k,n)<<'\n';
//	for(int i = 0;i<=k;i++){
//		for(int j = 0;j<=n;j++)cout<<dp[i][j]<<' ';cout<<'\n';
//	}
//	cout<<'\n';
}
int main(){
//	io
	int t;
	cin>>t;
	while(t--)solve();
}

