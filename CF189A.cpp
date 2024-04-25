#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int dp[n+1] = {};
	dp[0] = 1;
	for(int i = a;i<=n;i++){
		if(dp[i-a] != 0)dp[i] = max(dp[i],dp[i-a]+1);
	}
	for(int i = b;i<=n;i++){
		if(dp[i-b] != 0)dp[i] = max(dp[i],dp[i-b]+1);
	}
	for(int i = c;i<=n;i++){
		if(dp[i-c] != 0)dp[i] = max(dp[i],dp[i-c]+1);
	}
	cout<<dp[n]-1;
}

