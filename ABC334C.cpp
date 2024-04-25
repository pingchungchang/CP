#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int dp[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int arr[m+1];
	for(int i = 1;i<=m;i++)cin>>arr[i];
	int dp[m+1] = {};
	for(int i = 2;i<=m;i++){
		dp[i] = dp[i-2]+arr[i]-arr[i-1];
	}
	int ans = dp[m];
	if(m%2 == 0){
		cout<<ans;
		return 0;
	}
	ans = min(ans,dp[m-1]);
	int tans = 0;
	for(int i = m-2;i>=1;i-=2){
		tans += arr[i+2]-arr[i+1];
		ans = min(ans,tans+dp[i-1]);
	}
	cout<<ans;
}
