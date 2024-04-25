#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<vector<int>> paths(21);
vector<vector<ll>> dp(21,vector<ll>(1<<21,-1));
const ll mod = 1e9+7;
int n,m;
ll recursive(int now,ll t){
//	cout<<now<<' '<<t<<',';
	if(dp[now][t]!= -1){
		return dp[now][t];
	}
	if((t&(1<<now)) == 0){
//		cout<<now<<' '<<t<<endl<<endl;
		dp[now][t] = 0;
		return 0;
	}
	dp[now][t] = 0;
	for(int i:paths[now]){
		if((t&(1<<i)) == 0)continue;
		dp[now][t]+= recursive(i,t^(1<<now));
		dp[now][t]%=mod;
	}
	return dp[now][t];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a==b)continue;
		paths[b-1].push_back(a-1);
	}
	dp[0][1] = 1;
	dp[0][0] = 0;
	for(ll i = 2;i<(1<<n);i++){
		dp[0][i] = 0;
	}
	for(int i = 1;i<n;i++){
		dp[i][0] = 0;
		dp[i][1] = 0;
		dp[i][(1<<i)] = 0;
	}
//	cout<<(1<<n)-1<<endl;
	recursive(n-1,(1<<n)-1);
//	for(int i = 0;i<n;i++){
//		for(ll j = 0;j<(1<<n);j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	cout<<dp[n-1][(1<<n)-1];
}
