#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n>>s;
	int dp[2][4];
	bool roll = 0;
	int ans = 1e9;
	for(auto &i:dp)for(auto &j:i)j = 1e9;
	string start[] = {"LL","RL","LR","RR"};
	for(int ii = 0;ii<4;ii++){
		for(auto &i:dp)for(auto &j:i)j = 1e9;
		int tmp = 0;
		for(int i = 0;i<2;i++)if(s[i] != start[ii][i])tmp++;
		dp[roll][ii] = tmp;
		for(int i = 2;i<n;i++){
			roll ^= 1;
			for(auto &j:dp[roll])j = 1e9;
			dp[roll][0] = dp[roll^1][1]+(s[i] != 'L');
			dp[roll][1] = min(dp[roll^1][3],dp[roll^1][2])+(s[i] != 'L');
			dp[roll][2] = min(dp[roll^1][0],dp[roll^1][1])+(s[i] != 'R');
			dp[roll][3] = dp[roll^1][2]+(s[i] != 'R');
		}
		//cout<<ii<<":";for(auto &i:dp[roll])cout<<i<<' ';cout<<'\n';
		if(ii == 0)ans = min({ans,dp[roll][3],dp[roll][2]});
		else if(ii == 1)ans = min({ans,*min_element(dp[roll],dp[roll]+3)});
		else if(ii == 2)ans = min({ans,*min_element(dp[roll]+1,dp[roll]+4)});
		else if(ii == 3)ans = min({ans,dp[roll][0],dp[roll][1]});
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
