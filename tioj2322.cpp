#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 998244353;
const int mxn = 5050;
int arr[mxn];
pii range[mxn];
int dp[2][mxn];

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}
inline int mub(int a,int b){
	return mad(a,mod-b);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	int sum = 0;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],sum += arr[i],arr[i] += arr[i-1];
	for(int i = 1;i<=n;i++)cin>>range[i].fs;
	for(int i = 1;i<=n;i++)cin>>range[i].sc;
	bool roll = false;
	for(auto &i:dp[roll])i = 1;
	for(int i = 1;i<=n;i++){
		roll ^= 1;
		memset(dp[roll],0,sizeof(dp[roll]));
		for(int j = 0;j<=arr[i];j++){
			int r = max(-1,j-range[i].fs);
			int l = max(0,j-range[i].sc);
			if(r<0)dp[roll][j] = 0;
			else if(l<=0)dp[roll][j] = dp[roll^1][r];
			else dp[roll][j] = mub(dp[roll^1][r],dp[roll^1][l-1]);
		}
		//cout<<i<<":"<<endl;
		//for(int j = 0;j<=sum;j++)cout<<dp[roll][j]<<' ';cout<<endl;
		for(int j = 1;j<mxn;j++)dp[roll][j] = mad(dp[roll][j],dp[roll][j-1]);
	}
	cout<<dp[roll][sum];
}
