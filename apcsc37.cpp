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
	int n;
	cin>>n;
	int dp[2] = {};
	int pre = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		int tmp = dp[0];
		dp[0] = max(dp[0],dp[1]+pre);
		dp[1] = max(dp[1],tmp)+k;
		pre = k;
	}
	cout<<max(dp[0],dp[1]+pre);
}

