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
#pragma GCC optimize("O3")
int main(){
	io
	string a,b;
	cin>>a>>b;
	int n = a.size(),m = b.size();
	int dp[n+1][m+1] = {};
	for(int i = 1;i<=n;i++){
		for(int j =1;j<=m;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(a[i-1] == b[j-1])dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
		}
	}
	cout<<dp[n][m];
	return 0;
}

