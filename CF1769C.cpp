#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n+1];
	arr[0] = -9;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int dp[n][2] = {};
	int ans = 0;
	for(int i = 1;i<=n;i++){
		dp[i][0] = dp[i][1] = 1;
		if(arr[i] == arr[i-1]){
			dp[i][0] = dp[i-1][0];
			dp[i][1] = max(dp[i-1][1],dp[i-1][0]+1);
		}
		else if(arr[i] == arr[i-1]+1){
			dp[i][0] = max(dp[i-1][1],dp[i-1][0]+1);
			dp[i][1] = dp[i-1][1]+1;
		}
		else if(arr[i] == arr[i-1]+2){
			dp[i][0] = dp[i-1][1]+1;
		}
		ans = max(ans,*max_element(dp[i],dp[i]+2));
	}
	//for(int i = 1;i<=n;i++)cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
