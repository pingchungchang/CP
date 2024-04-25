#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> dp;
int n;
vector<pair<int,int>> v;
double dis(int a,int b){
	return sqrt((v[a].first-v[b].first)*(v[a].first-v[b].first)+(v[a].second-v[b].second)*(v[a].second-v[b].second));
}
void rec(int now,int type){
	if(dp[now][type]!= INT_MAX)return;
	for(int i = 0;i<n;i++){
		if((type&(1<<i)) != 0){
			rec(i,type^(1<<now));
			dp[now][type] = min(dp[now][type],dp[i][type^(1<<now)]+dis(now,i));
		}
	}
	return;
}
int main(){
	cin>>n;
	dp = vector<vector<double>>(n,vector<double>(1<<n,INT_MAX));
	v = vector<pair<int,int>>(n);
	for(int i = 0;i<n;i++)cin>>v[i].first>>v[i].second;
	for(int i = 0;i<n;i++){
		dp[i][1<<i] = 0;
	}
	for(int i = 0;i<n;i++){
		rec(i,(1<<n)-1);
	}
//	for(int i = 0;i<dp.size();i++){
//		for(int j = 0;j<dp[0].size();j++)cout<<dp[i][j]<<' ';
//		cout<<endl;
//	}
	double ans = INT_MAX;
	for(int i = 0;i<n;i++){
		ans = min(ans,dp[i][(1<<n)-1]);
	}
	printf("%.2f",ans);
}
