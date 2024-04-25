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

const int mxn = 1<<22;
int dp[mxn];
const int bits = 22;
int main(){
	io
	int n;
	cin>>n;
	fill(dp,dp+mxn,-1LL);
	int arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		dp[arr[i]] = arr[i];
	}
	for(int i = 0;i<bits;i++){
		for(int j = 0;j<mxn;j++){
			dp[j|(1<<i)] = max(dp[j|(1<<i)],dp[j]);
		}
	}
	for(int i = 0;i<n;i++){
		bitset<bits> tmp(arr[i]);
		tmp.flip();
		int k = tmp.to_ulong();
		cout<<dp[k]<<' ';
	}
	return 0;
}

