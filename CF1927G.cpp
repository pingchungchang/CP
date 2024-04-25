#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 110;
const int inf = 1e5+10;
int dp[mxn][2];
int arr[mxn];
pii range[mxn];
int n;

void solve(){
	for(auto &i:dp)for(auto &j:i)j = inf;
	dp[0][0] = dp[0][1] = 0;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],range[i] = make_pair(max(0,i-arr[i]+1),min(n,i+arr[i]-1));
	for(int i = 1;i<=n;i++){
		for(int j = i-1;j>=0;j--){
			if(j>=range[i].fs-1)dp[i][0] = min(dp[i][0],dp[j][0]+1);
			if(range[j].sc>=range[i].fs-1)dp[i][0] = min(dp[i][0],dp[j][1]+1);
			if(j>=i-1)dp[i][1] = min(dp[i][1],dp[j][0]+1);
			if(range[j].sc>=i-1)dp[i][1] = min(dp[i][1],dp[j][1]+1);
		}
	}
	int ans = inf;
	for(int i = 1;i<=n;i++){
		if(range[i].sc>=n)ans = min(ans,dp[i][1]);
		if(i==n)ans = min(ans,dp[i][0]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
