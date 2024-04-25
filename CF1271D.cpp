#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5050;
const ll inf = 1e9;
ll dp[2][mxn];
ll arr[mxn],brr[mxn],crr[mxn];
int n,m,st;
int cap[mxn];
vector<int> paths[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>st;
	for(int i = 1;i<=n;i++){
		cin>>arr[i]>>brr[i]>>crr[i];
	}
	for(int i = 1;i<=n;i++)cap[i] = i;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		cap[b] = max(cap[b],a);
	}
	for(int i = 1;i<=n;i++){
		paths[cap[i]].push_back(crr[i]);
	}
	for(int i = 1;i<=n;i++)sort(paths[i].rbegin(),paths[i].rend());
	memset(dp,-1,sizeof(dp));
	bool roll = 0;
	dp[roll][st] = 0;
	/*
	for(int i = 1;i<=n;i++){
		cout<<i<<":";for(auto &j:paths[i])cout<<j<<' ';cout<<endl;
	}return 0;

   */
	for(int i = 1;i<=n;i++){
		roll ^= 1;
		memset(dp[roll],-1,sizeof(dp[roll]));
		for(int j = arr[i];j<mxn;j++){
			if(dp[roll^1][j] < 0)continue;
			ll sum = 0;
			dp[roll][j+brr[i]] = dp[roll^1][j];
			for(int k = 0;k<paths[i].size();k++){
				if(k+1>j+brr[i])break;
				sum += paths[i][k];
				dp[roll][j+brr[i]-k-1] = max(dp[roll][j+brr[i]-k-1],sum+dp[roll^1][j]);
			}
		}
	}
	cout<<*max_element(dp[roll],dp[roll]+mxn);
}
