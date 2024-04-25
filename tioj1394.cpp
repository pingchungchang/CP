#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<int> tree[mxn];
int dp[mxn][2];

void dfs(int now){
	dp[now][1] = 1;
	for(auto nxt:tree[now]){
		dfs(nxt);
		dp[now][0] += dp[nxt][1];
		dp[now][1] += min(dp[nxt][1],dp[nxt][0]);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		while(k--){
			int tmp;
			cin>>tmp;
			tree[i].push_back(tmp);
		}
	}
	dfs(0);
	/*
	for(int i = 0;i<n;i++){
		cout<<dp[i][0]<<','<<dp[i][1]<<endl;
	}

   */
	cout<<min(dp[0][0],dp[0][1]);
}
