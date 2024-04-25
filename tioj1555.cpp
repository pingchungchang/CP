#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5050;
short dp[mxn][mxn];
int n,m;
int arr[mxn];
short ans = 0;
ll cnt = 0;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		string s;
		cin>>s;
		for(int j = 1;j<=m;j++){
			if(s[j-1] == '1')dp[i][j] = 0;
			else dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
			ans = max(ans,dp[i][j]);
			cnt += dp[i][j];
		}
	}
	cout<<cnt<<' '<<ans;
}
