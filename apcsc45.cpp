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
const ll mxn = 1e5+10;
ll dp[mxn];
int main(){
	io
	int n,w;
	cin>>n>>w;
	for(int i = 0;i<n;i++){
		int u,v;
		cin>>u>>v;
		for(int j = w;j>=u;j--){
			dp[j] = max(dp[j],dp[j-u]+v);
		}
	}
	cout<<dp[w];
}

