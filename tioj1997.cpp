#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e6+10;
const ll inf = 5e18;
ll dp[mxn][7];
pii pre[mxn][7];
ll arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(auto &i:dp)for(auto &j:i)j = -inf;
	dp[1][0] = arr[1];
	pre[1][0] = {0,0};
	k--;
	for(int i = 2;i<=n;i++){
		pre[i][0] = {i-1,0};
		dp[i][0] = dp[i-1][0]+arr[i];
		for(int j = 1;j<=k;j++){
			if(j&1){
				dp[i][j] = dp[i-1][j]-arr[i];
				pre[i][j] = {i-1,j};
				if(dp[i-1][j-1]-arr[i]>dp[i][j]){
					dp[i][j] = dp[i-1][j-1]-arr[i];
					pre[i][j] = {i-1,j-1};
				}
			}
			else{
				dp[i][j] = dp[i-1][j]+arr[i];
				pre[i][j] = {i-1,j};
				if(dp[i-1][j-1]+arr[i]>dp[i][j]){
					dp[i][j] = dp[i-1][j-1]+arr[i];
					pre[i][j] = {i-1,j-1};
				}
			}
		}
	}
	//cout<<dp[n][k]<<endl;
	pii now = {n,k};
	vector<ll> ans;
	while(now.fs != 0){
		if(pre[now.fs][now.sc].sc != now.sc)ans.push_back(now.fs-1);
		now = pre[now.fs][now.sc];
	}
	reverse(ans.begin(),ans.end());
	for(auto &i:ans)cout<<i<<' ';
	return 0;
}
