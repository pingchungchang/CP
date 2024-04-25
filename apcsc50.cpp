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
int main(){
	io
	int n;
	cin>>n;
	vector<pii> v(n);
	int dp[n+1] = {};
	fill(dp,dp+n+1,INT_MAX);
	for(int i = 0;i<n;i++)cin>>v[i].fs>>v[i].sc;
	sort(_all(v));
	for(int i= 0;i<n;i++){
		auto it = upper_bound(dp,dp+n+1,v[i].sc)-dp;
		dp[it] = v[i].sc;
	}
	cout<<lower_bound(dp,dp+n+1,INT_MAX)-dp;
}

