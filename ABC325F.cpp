#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxN = 110;
const int mxK = 1010;
const int inf = 4e18;
int n;
int dp[2][mxK];
int arr[mxN];
int len[2],cost[2],cnt[2];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	bool roll = 0;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<2;i++)cin>>len[i]>>cost[i]>>cnt[i];
	for(auto &i:dp)for(auto &j:i)j = inf;
	dp[roll][0] = 0;
	for(int i = 0;i<n;i++){
		//for(int j = 0;j<=cnt[0];j++)cout<<dp[roll][j]<<' ';cout<<endl;
		roll ^= 1;
		for(auto &j:dp[roll])j = inf;
		for(int j = 0;j<=cnt[0];j++){
			for(int l = 0;l<=j;l++){
				int c2 = max(0ll,arr[i]-l*len[0]);
				c2 = (c2+len[1]-1)/len[1];
				dp[roll][j] = min(dp[roll][j],dp[roll^1][j-l]+l*cost[0]+c2*cost[1]);
			}
		}
	}
	int ans = inf;
	for(int i = 0;i<=cnt[0];i++){
		int c2 = dp[roll][i]-i*cost[0];
		c2 /= cost[1];
		if(c2<=cnt[1])ans = min(ans,dp[roll][i]);
	}
	//for(int i = 0;i<=cnt[0];i++)cout<<dp[roll][i]<<' ';cout<<endl;
	cout<<(ans>=inf?-1:ans);
}
