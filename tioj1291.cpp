#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const ll mod = 1e6;
const int mxn = 220;
int n,m;
int com[mxn][mxn];
ll dp[mxn][mxn];

inline int mad(int a,int b){
	a+=b;
	return a>=mod?a-mod:a;
}

inline int C(int a,int b){
	if(a<0||b>a)return 0;
	if(!b)com[a][b] = 1;
	if(com[a][b]!=-1)return com[a][b];
	else return com[a][b] = mad(C(a-1,b),C(a-1,b-1));
}
inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}

void solve(){
	int ans = 0;
	n = min(n,m);
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			dp[i][j] = mad(dp[i-1][j-1],dp[i-1][j]*j%mod);
		}
	}
	for(int i = 1;i<=n;i++)ans = mad(ans,dp[m][i]);
	/*
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++)cout<<dp[i][j]<<' ';cout<<endl;
	}

   */
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(com,-1,sizeof(com));
	while(cin>>n>>m){
		if(!n&&!m)return 0;
		solve();
	}
}
