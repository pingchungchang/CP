#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 404;
int n,m,k;
ll dp[mxn][mxn];
ll arr[mxn],brr[mxn];

inline ll calc(){
	dp[1][1] = (arr[1]-brr[1])*(arr[1]-brr[1]);
	for(int i = 2;i<=n;i++)dp[i][1] = dp[i-1][1]+(arr[i]-brr[1])*(arr[i]-brr[1]);
	for(int i = 2;i<=m;i++)dp[1][i] = dp[1][i-1]+(arr[1]-brr[i])*(arr[1]-brr[i]);
	for(int i = 2;i<=n;i++){
		for(int j = 2;j<=m;j++){
			dp[i][j] = min({dp[i-1][j],dp[i][j-1]})+(arr[i]-brr[j])*(arr[i]-brr[j]);
		}
	}
	return dp[n][m];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(n>400)exit(0);
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=m;i++)cin>>brr[i];
	while(k--){
		int t,a,b;
		cin>>t>>a>>b;
		if(t == 1)arr[a] = b;
		else brr[a] = b;
		cout<<calc()<<'\n';
	}
	return 0;
}
