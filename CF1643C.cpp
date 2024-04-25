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
	string s;
	cin>>s;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll dp[2][n];
	memset(dp,0LL,sizeof(dp));
	if(s[0] == '1'){
		dp[0][0] = INT_MIN;
		dp[1][0] = arr[0];
	}
	for(int i = 1;i<n;i++){
		if(s[i] == '0'){
			dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
			dp[1][i] = INT_MIN;
		}
		else{
			dp[0][i] = dp[0][i-1]+arr[i-1];
			dp[1][i] = max(dp[0][i-1],dp[1][i-1])+arr[i];
		}
	}
	cout<<max(dp[0][n-1],dp[1][n-1])<<"\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

