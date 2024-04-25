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
const ll mxn = 1e3+10;
ll dp[mxn][mxn];
int main(){
	string a,b;
	cin>>a>>b;
	if(a[0] != b[0])dp[0][0] = 1;
	for(int i = 1;i<a.size();i++){
		dp[i][0] = dp[i-1][0]+1;
		if(a[i] != b[0])dp[i][0]= i;
	}
	for(int j = 1;j<b.size();j++){
		dp[0][j] = dp[0][j-1]+1;
	}
	for(int i = 1;i<a.size();i++){
		for(int j = 1;j<b.size();j++){
			dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			if(a[i] == b[j])dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
		}
	}
	cout<<dp[a.size()-1][b.size()-1];
}

