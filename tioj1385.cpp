#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
int dp[mxn][mxn];

int main(){
	for(auto &i:dp)for(auto &j:i)j = 1e9;
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int n = a.size(),m = b.size();
	a = "#"+a,b = "#"+b;
	dp[0][0] = 0;
	for(int i = 0;i<=n;i++)dp[i][0] = i;
	for(int i = 0;i<=m;i++)dp[0][i] = i;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(a[i] == b[j])dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = min({dp[i][j],dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
			}
		}
	}
	cout<<dp[n][m];
}
