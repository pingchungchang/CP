#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
ll dp[mxn][mxn];
ll sum = 0;
int n;

void solve(){
	cin>>n;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	for(int i = 0;i<n;i++)dp[i][i] = 0;
	for(int len = 2;len<=n;len++){
		for(int head = 0;head+len<=n;head++){
			dp[head][head+len-1] = 1e18;
			for(int mid = head;mid<head+len-1;mid++){
				dp[head][head+len-1] = min(dp[head][head+len-1],
							dp[head][mid]+dp[mid+1][head+len-1]+arr[head].fs*arr[head+len-1].sc*arr[mid].sc);
			}
		}
	}
	/*
	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++)cout<<setw(5)<<dp[i][j]<<' ';cout<<endl;
	}

   */
	sum += dp[0][n-1];
	cout<<(dp[0][n-1]+999)/1000<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	cout<<(sum+999)/1000;
}
