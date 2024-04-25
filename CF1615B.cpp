#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const int mxn = 2e5+10;
int dp[mxn][32];
void solve(){
	int l,r;
	cin>>l>>r;
	int ans = INT_MAX;
	for(int i = 0;i<32;i++){
		ans = min(ans,r-l+1-(dp[r][i]-dp[l-1][i]));
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 1;i<mxn;i++){
		int now = i;
		for(int j = 0;j<=31;j++){
			dp[i][j] += dp[i-1][j];
			if((now&1))dp[i][j]++;
			now>>=1;
		}
	}
	while(t--)solve();
}

