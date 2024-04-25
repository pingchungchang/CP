#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 17;
int arr[mxn][mxn];
ll dp[1<<mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			cin>>arr[i][j];
			arr[j][i] = arr[i][j];
		}
	}
	dp[0] = 0;
	for(int i = 0;i<(1<<n);i++){
		for(int j = 0;j<n;j++){
			if(i&(1<<j))continue;
			for(int l = j+1;l<n;l++){
				if(i&(1<<l))continue;
				dp[i^(1<<j)^(1<<l)] = max(dp[i^(1<<j)^(1<<l)],dp[i]+arr[j][l]);
			}
		}
		//cout<<dp[i]<<' ';
	}
	cout<<dp[(1<<n)-1];
}
