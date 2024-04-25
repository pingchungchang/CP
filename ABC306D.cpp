#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 3e5+10;
ll dp[mxn][2];
pll arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 1;i<=n;i++){
		if(arr[i].fs){
			dp[i][0] = dp[i-1][0];
			dp[i][1] = max(dp[i-1][0]+arr[i].sc,dp[i-1][1]);
		}
		else{
			dp[i][0] = max({dp[i-1][0],dp[i-1][0]+arr[i].sc,dp[i-1][1]+arr[i].sc});
			dp[i][1] = dp[i-1][1];
		}
	}
	cout<<max(dp[n][0],dp[n][1]);
}
