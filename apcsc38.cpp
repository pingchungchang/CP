#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	int n;
	cin>>n;
	short now = 1;
	int dp[2][2] = {};
	int ans = 0;
	for(int i = 0;i<n;i++){
		now ^= 1;
		int k;
		cin>>k;
		dp[now][0] = max(dp[now^1][0],dp[now^1][1]);
		dp[now][1] = max(dp[now][0],dp[now^1][0]+k);
		cout<<dp[now][0]<<' '<<dp[now][1]<<endl;
		ans = max(ans,max(dp[now][0],dp[now][1]));
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

