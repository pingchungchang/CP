#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 420;
int dp[mxn][mxn];

void solve(){
	for(auto &i:dp)for(auto &j:i)j = mxn*mxn*mxn;
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	dp[0][0] = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<mxn;j++){
			for(int k = 0;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i-1][k]+abs(j-arr[i-1]));
			}
		}
	}
	cout<<*min_element(dp[n],dp[n]+mxn)<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
