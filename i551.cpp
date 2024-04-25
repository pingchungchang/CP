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
int n;
void solve(){
	pii arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	int w;
	cin>>w;
	int dp[w+1] = {};
	for(int i = 0;i<n;i++){
		for(int j = w;j>=arr[i].fs;j--)dp[j] = max(dp[j],dp[j-arr[i].fs]+arr[i].sc);
	}
	cout<<dp[w]<<'\n';
	return;
}
int main(){
	io
	while(cin>>n)solve();
}

