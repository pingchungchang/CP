#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define int ll

const int mxn = 5050;
int dp[2][mxn];

void solve(){
	int n;
	cin>>n;
	int arr[n+1] = {};
	for(int i =1 ;i<=n;i++)cin>>arr[i];
	bool roll = 0;
	fill(dp[roll],dp[roll]+mxn,mxn*mxn);
	int s = -1;
	for(int i = 1;i<=n;i++)if(arr[i]){
		s = i;
		break;
	}
	if(s == -1){
		cout<<"0\n";
		return;
	}
	for(int i = 1;i<=n;i++){
		if(!arr[i])dp[roll][i] = abs(i-s);
	}
	for(int i = 1;i<=n;i++)dp[roll][i] = min(dp[roll][i],dp[roll][i-1]);
	for(int i = s+1;i<=n;i++){
		if(!arr[i])continue;
		roll ^= 1;
		fill(dp[roll],dp[roll]+mxn,mxn*mxn);
		for(int j = 1;j<=n;j++){
			if(!arr[j])dp[roll][j] = dp[roll^1][j-1]+abs(j-i);
		}
		for(int j = 1;j<=n;j++)dp[roll][j] = min(dp[roll][j],dp[roll][j-1]);
		//for(int j = 1;j<=n;j++)cout<<dp[roll][j]<<' ';cout<<endl;
	}
	cout<<dp[roll][n]<<'\n';
	return;
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
