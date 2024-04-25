#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 17;
const ll inf = 1e18;
int dist[mxn][mxn];
ll dp[mxn][1<<mxn];
pii pos[mxn];
int dt[mxn];
int n,m;

ll calc(ll a,ll b,ll t){
	t += dist[a][b];
	return (t+dt[b]-1)/dt[b]*dt[b];
}

void solve(){
	if(!n&&!m)exit(0);
	dt[0] = 1;
	pos[0] = {1,1};
	for(int i = 1;i<=m;i++){
		cin>>pos[i].fs>>pos[i].sc;
		cin>>dt[i];
	}
	for(int i = 0;i<=m;i++){
		for(int j = 0;j<=m;j++){
			dist[i][j] = dist[j][i] = abs(pos[i].fs-pos[j].fs)+abs(pos[i].sc-pos[j].sc);
		}
	}
	m++;
	/*
	for(int i = 0;i<m;i++){
		for(int j = 0;j<m;j++)cout<<dist[i][j]<<' ';cout<<'\n';
	}

   */
	for(int i = 0;i<m;i++)for(int j = 0;j<(1<<m);j++)dp[i][j] = inf;
	dp[0][1] = 0;
	for(int i = 0;i<(1<<m);i++){
		for(int j = 0;j<m;j++){
			//for(int l = 0;l<m;l++)if(i&(1<<l))cout<<1;else cout<<0;cout<<" "<<j<<":"<<dp[j][i]<<'\n';
			if(!(i&(1<<j)))continue;
			if(dp[j][i]>=inf)continue;
			for(int k = 0;k<m;k++){
				if(i&(1<<k))continue;
				dp[k][i|(1<<k)] = min(dp[k][i|(1<<k)],calc(j,k,dp[j][i]));
			}
		}
	}
	ll ans = inf;
	for(int i = 0;i<m;i++)ans = min(ans,dp[i][(1<<m)-1]);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>m)solve();
}
