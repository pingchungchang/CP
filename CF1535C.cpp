#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	string s;
	cin>>s;
	ll n = s.size();
	vector<vector<ll>> dp(n,vector<ll>(3,0LL));
	if(s[0] != '1')dp[0][0] = 1;
	if(s[0] != '0')dp[0][1] = 1;
	if(s[0] == '?')dp[0][2] = 1;
	for(int i = 1;i<n;i++){
		if(s[i] == '?'){
			if(s[i-1] == '?')dp[i][2] = dp[i-1][2]+1;
			else dp[i][2] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+1;
			dp[i][1] = dp[i-1][0]+1;
			dp[i][0] = dp[i-1][1]+1;
		}
		if(s[i] == '1')dp[i][1] = dp[i-1][0]+1;
		if(s[i] == '0')dp[i][0] = dp[i-1][1]+1;
	}
	ll total = 0;
	for(ll i = 0;i<n;i++){
		if(s[i] == '0')total += dp[i][0];
		else if(s[i] == '1')total += dp[i][1];
		else total += dp[i][2];
	}
//	for(int i = 0;i<n;i++)cout<<dp[i][0]<<' ';cout<<'\n';for(int i = 0;i<n;i++)cout<<dp[i][1]<<' ';cout<<'\n';for(int i = 0;i<n;i++)cout<<dp[i][2]<<' ';cout<<"\n\n";
	cout<<total<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

