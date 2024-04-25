#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const int mxn = 1<<17;
ld dp[17][mxn];
int speed[mxn];
ld dist[17][17];
const ll inf = 5e18;
int main(){
	int n,m;
	cin>>n>>m;
	for(auto &i:dp){
		for(auto &j:i)j = inf;
	}
	for(int i = 0;i<(1<<(n+m));i++){
		int cnt = 0;
		for(int j = n;j<n+m;j++){
			if(i&(1<<j))cnt++;
		}
		speed[i] = (1<<cnt);
	}
	pll pos[n+m];
	for(int i = 0;i<n;i++)cin>>pos[i].fs>>pos[i].sc;
	for(int i = n;i<n+m;i++)cin>>pos[i].fs>>pos[i].sc;
	for(int i = 0;i<n+m;i++){
		for(int j = 0;j<n+m;j++){
			dist[i][j] = dist[j][i] = sqrt((pos[i].fs-pos[j].fs)*(pos[i].fs-pos[j].fs)+(pos[i].sc-pos[j].sc)*(pos[i].sc-pos[j].sc));
		}
	}
	for(int i = 0;i<n+m;i++){
		dp[i][1<<i] = sqrt(pos[i].fs*pos[i].fs+pos[i].sc*pos[i].sc);
	}
	for(int i = 0;i<(1<<(n+m));i++){
		for(int j = 0;j<n+m;j++){
			if(!(i&(1<<j)))continue;
			for(int k = 0;k<(n+m);k++){
				if(k == j||!(i&(1<<k)))continue;
				dp[j][i] = min(dp[j][i],dp[k][i^(1<<j)]+dist[j][k]/speed[i^(1<<j)]);
			}
		}
	}
	ld ans = inf;
	for(int i = 0;i<(1<<(n+m));i++){
		for(int j = 0;j<n+m;j++){
			int cnt = 0;
			for(int k = 0;k<n;k++)if(i&(1<<k))cnt++;
			if(cnt == n){
//				cout<<i<<' '<<j<<' '<<dp[j][i]<<endl;
				ans = min(ans,dp[j][i]+sqrt(pos[j].fs*pos[j].fs+pos[j].sc*pos[j].sc)/speed[i]);
			}
		}
	}
	cout<<fixed<<setprecision(10)<<ans;
}

