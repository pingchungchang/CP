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
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	ll dp[n][m+1][m+1] = {};
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=m;j++){
			for(int k = 0;k<=m;k++)dp[i][j][k] = INT_MAX;
		}
	}
	dp[0][arr[0]][arr[0]] = 0;
}
//dp[i][j][k]:ith j pans k used
