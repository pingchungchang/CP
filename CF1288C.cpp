#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 1100;
const ll mod = 1e9+7;
ll dp[2][mxn][mxn];
ll n,m;
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool roll = 0;
	for(auto &i:dp[roll])for(auto &j:i)j = 1;
	for(int i = 1;i<=m;i++){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		for(int j = 1;j<=n;j++){
			for(int k = j;k<=n;k++){
				dp[roll][j][k] = dp[roll^1][j][k];
			}
		}
		for(int j = 1;j<=n;j++){
			for(int k = n;k>=1;k--){
				dp[roll][j][k] = dp[roll][j][k]+dp[roll][j-1][k]+dp[roll][j][k+1]-dp[roll][j-1][k+1];
				while(dp[roll][j][k]<0)dp[roll][j][k] += mod;
				dp[roll][j][k]%= mod;
			}
		}
	}
	cout<<dp[roll][n][1];
}
