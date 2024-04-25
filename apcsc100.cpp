#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mod = 998244353;
vector<vector<ll>> dp(3030,vector<ll>(3030,0));
void solve(){
	ll n,m;
	cin>>n>>m;
	cout<<dp[n][m]<<'\n';
	return;
}
int main(){
	io
	for(int i = 1;i<=6;i++)dp[1][i] = 1;
	for(int i = 2;i<=3000;i++){
		for(int j = 1;j<=3000;j++){
			for(int k = 1;k<=6;k++){
				if(j-k>0)dp[i][j] = (dp[i][j]+dp[i-1][j-k]>=mod?dp[i][j]+dp[i-1][j-k]-mod:dp[i][j]+dp[i-1][j-k]);
			}
		}
	}
	int t;
	cin>>t;
	while(t--)solve();
}

