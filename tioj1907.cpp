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
void solve(){
	int m;
	cin>>m;
	int dp[1001] = {};
	pii arr[m];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	for(auto &i:arr)i.sc = -i.sc;
	sort(arr,arr+m);
	for(auto &i:arr)i.sc = -i.sc;
	int ans = 0;
	for(int i = 0;i<m;i++){
		int tmp = 0;
		for(int j = 0;j<arr[i].sc;j++)tmp = max(tmp,dp[j]);
		dp[arr[i].sc] = max(dp[arr[i].sc],tmp+1);
	}
	cout<<*max_element(dp,dp+1001)<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

