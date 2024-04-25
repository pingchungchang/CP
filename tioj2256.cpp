#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 45;
const int inf = 1e18;
int sell[mxn][mxn];
int n;
int T;
int num[mxn];
int mov[mxn],ask[mxn];
int dp[mxn][mxn*mxn];

pii cnt(int l,int r){
	pii re = {0,0};
	for(int i = l+1;i<=r;i++){
		re.fs += sell[r][i];
		re.sc += num[i];
	}
	return re;
}

int calc(int l,int r){
	int total = 0;
	for(int i = l+1;i<=n;i++){
		total += num[i];
	}
	int re = 0;
	for(int i = l+1;i<=r;i++){
		re += total*mov[i];
	}
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>T;
	for(auto &i:dp)for(auto &j:i)j = inf;
	dp[0][0] = 0;
	for(int i = 1;i<=n;i++)cin>>mov[i];
	for(int i = 1;i<=n;i++)cin>>ask[i];
	for(int i = 1;i<=n;i++)cin>>num[i];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++)cin>>sell[i][j];
	}

	for(int i = 1;i<=n+1;i++){
		for(int j = 0;j<mxn*mxn;j++){
			for(int k = i-1;k>=0;k--){
				if(dp[k][j] >= inf)continue;
				auto p = cnt(k,i);
				int sh = calc(k,i);
				//assert(j+p.fs<mxn*mxn);
				dp[i][j+p.fs] = min(dp[i][j+p.fs],dp[k][j]+sh+p.sc*ask[i]);
			}
		}
	}

	/*
	for(int i = 1;i<=n+1;i++){
		for(int j = 0;j<=20;j++)cout<<(dp[i][j]==inf?-1:dp[i][j])<<' ';cout<<endl;
	}
   */
	int ans = -1;
	for(int i = 0;i<mxn*mxn;i++){
		if(dp[n+1][i]<=T)ans = i;
	}
	cout<<ans;
}
