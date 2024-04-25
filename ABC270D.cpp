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
	int n,k;
	cin>>n>>k;
	int dp[n+1] = {};
	int arr[k];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<k&&arr[j]<=i;j++){
			dp[i] = max(dp[i],i-dp[i-arr[j]]);
//			cout<<i<<' '<<j<<' '<<i-dp[i-j]<<' '<<dp[i]<<endl;
		}
	}
//	for(int i = 0;i<=n;i++)cout<<dp[i]<<' ';
	cout<<dp[n];
}

