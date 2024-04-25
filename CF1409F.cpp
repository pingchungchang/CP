#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll inf = 1e9;
const ll mxn = 202;
ll dp[2][mxn][mxn];
//dp[i][cnt][acnt];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	bool roll = 0;
	int n,k;
	cin>>n>>k;
	string a,b;
	cin>>a>>b;
	for(auto &i:dp)for(auto &ii:i)for(auto &iii:ii)iii = -inf;
	dp[roll][0][0] = 0;
	ll ans = 0;
	for(int i = 0;i<a.size();i++){
		roll ^= 1;
		for(auto &ii:dp[roll])for(auto &iii:ii)iii = -inf;
		for(int j = 0;j<=k;j++){
			for(int l = 0;l<=n;l++){
				dp[roll][j][l] = dp[roll^1][j][l]+(a[i] == b[1]?l:0);
				if(a[i] == b[0]){
					if(l != 0){
						dp[roll][j][l] = max(dp[roll][j][l],dp[roll^1][j][l-1]+(a[i] == b[1]?l-1:0));
					}
				}
				if(j != 0&&l != 0){
					dp[roll][j][l] = max(dp[roll][j][l],dp[roll^1][j-1][l-1]+(b[0] == b[1]?l-1:0));
				}
				if(j != 0&&b[0] != b[1])dp[roll][j][l] = max(dp[roll][j][l],dp[roll^1][j-1][l]+l);
				ans = max(ans,dp[roll][j][l]);
			}
		}
	}
	cout<<ans;
}
