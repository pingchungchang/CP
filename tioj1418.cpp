#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#pragma GCC optimize("O3")
const int mxn = 21;
const int inf = 1e9;
int arr[mxn][mxn];
int dp[1<<mxn];
void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)cin>>arr[i][j];
	fill(dp,dp+(1<<n),inf);
	dp[0] = 0;
	for(int i = 0;i<(1<<n);i++){
		if(dp[i]==inf)continue;
		for(int j = 0;j<n;j++){
			if(!(i&(1<<j))){
				for(int k = j+1;k<n;k++){
					if(!(i&(1<<k))){
						for(int l = k+1;l<n;l++){
							if(!(i&(1<<l))){
								dp[i^(1<<j)^(1<<k)^(1<<l)] = min(dp[i^(1<<j)^(1<<k)^(1<<l)],arr[l][j]+arr[j][k]+arr[l][k]+dp[i]);
							}
						}
					}
				}
				break;
			}
		}
	}
	cout<<dp[(1<<n)-1]<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}


