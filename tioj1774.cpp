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
const ll mxn =2020;
ll dp[mxn];
int main(){
	io
	ll n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		for(int j = b;j<=m;j++)dp[j] = max(dp[j],dp[j-b]+a);
	}
	cout<<dp[m];
}

