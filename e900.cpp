#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 1010;
const int inf = mxn*mxn;
int n;
void solve(){
	pii arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	bool roll = 0;
	int total = 0;
	for(auto &i:arr)total += i.fs+i.sc;
	int dp[2][total+1];
	fill(dp[roll],dp[roll]+total+1,inf);
	dp[roll][0] = 0;
	for(int i = 0;i<n;i++){
		roll ^= 1;
		fill(dp[roll],dp[roll]+total+1,inf);
		for(int j = arr[i].fs;j<=total;j++)dp[roll][j] = min(dp[roll][j],dp[roll^1][j-arr[i].fs]);
		for(int j = arr[i].sc;j<=total;j++)dp[roll][j] = min(dp[roll][j],dp[roll^1][j-arr[i].sc]+1);
		//for(int j = 0;j<=total;j++)cout<<dp[roll][j]<<' ';cout<<endl;
	}
	pii ans = {inf*mxn,0};
	for(int i = 1;i<=total;i++){
		if(dp[roll][i]<inf)ans = min(ans,make_pair(abs(total-i*2),dp[roll][i]));
	}
	//cout<<ans.fs<<' ';
	cout<<ans.sc<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
