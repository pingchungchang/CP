#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn = 15;
int dp[1<<mxn];
int n;
int arr[mxn][mxn],brr[mxn][mxn];

void solve(){
	memset(dp,0,sizeof(dp));
	for(int i = 0;i<n;i++)for(int j  =0;j<n;j++)cin>>arr[i][j];
	for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)cin>>brr[i][j];
	int ans = 0;
	for(int i = (1<<n)-1;i>=0;i--){
		ans = max(ans,dp[i]);
		for(int j = 0;j<n;j++){
			for(int k = j+1;k<n;k++){
				if((i&(1<<j))&&(i&(1<<k))){
					int nxt = i^(1<<j)^(1<<k)^(1<<brr[j][k]);
					dp[nxt] = max(dp[nxt],dp[i]+arr[j][k]);
				}
			}
		}
	}
	cout<<ans<<'\n';
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
