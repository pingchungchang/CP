#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 998244353;
const ll mxn = 2022;
ll n,m;
string arr[mxn];
ll dp[mxn][mxn*2];
ll range[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(arr[i][j] == '#'){
				if(i+1<n)arr[i+1][j] = '#';
				if(i+1<n&&j+1<m)arr[i+1][j+1] = '#';
			}
		}
	}
	for(int i = 0;i<m;i++){
		ll c = n;
		for(int j = 0;j<n;j++){
			if(arr[j][i] == '#'){
				c = j;
				break;
			}
		}
		range[i+1] = c;
	}
	for(int i = 0;i<mxn*2;i++)dp[0][i] = 1;
	for(int i = 1;i<=m;i++){
		dp[i][mxn*2-1] = 1;
		for(int j = 0;j<mxn*2-1;j++){
			dp[i][j] = dp[i-1][j]-dp[i-1][j+1];
			if(dp[i][j]<0)dp[i][j] += mod;
		}
		for(int j = 1;j<=range[i];j++){
			dp[i][mxn+j-i] += dp[i-1][mxn+j-i+1];
			if(dp[i][mxn+j-i]>=mod)dp[i][mxn+j-i]-= mod;
		}
		//for(int j = 0;j<=n*2;j++)cout<<dp[i][j]<<' ';cout<<'\n';
		for(int j = mxn*2-2;j>=0;j--){
			assert(dp[i][j]<mod);
			dp[i][j] += dp[i][j+1];
			if(dp[i][j]>=mod)dp[i][j] -= mod;
		}
	}
	cout<<dp[m][0];
}
