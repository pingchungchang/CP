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

const ll mod = 1e9+7;
void solve(){
	int n,m,s,e;
	cin>>n>>m>>s>>e;
	vector<int> paths[n+1];
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	ll dist[n+1],cnt[n+1][2];
	fill(dist,dist+n+1,INT_MAX);
	memset(cnt,0LL,sizeof(cnt));
	queue<pll> q;
	dist[s] = 0;
	bool secin[n+1] = {};
	cnt[0][0] = 1;
	q.push({s,0});
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now.fs]){
			if(dist[nxt] == INT_MAX){
				dist[nxt] = now.sc+1;
				cnt[nxt][0]++;
				q.push({nxt,dist[nxt]});
			}
			else if(dist[nxt] == now.sc+1){
				cnt[nxt][0]++;
			}
			else if(dist[nxt]+1 == now.sc+1){
				cnt[nxt][1]++;
				if(!secin[nxt]){
					secin[nxt] =true;
					q.push({nxt,now.sc+1});
				}
			}
		}
	}
	ll dp[n+1][2];
	memset(dp,0LL,sizeof(dp));
	dp[s][0] = 1;
	queue<pair<ll,pll>> qq;
	qq.push({s,{0,0}});
	while(!qq.empty()){
		auto now = qq.front();
		qq.pop();
		for(auto nxt:paths[now.fs]){
			if(dist[nxt] == now.sc.fs+1){
				cnt[nxt][0]--;
				dp[nxt][0] += dp[now.fs][now.sc.sc];
				if(cnt[nxt][0] == 0)qq.push({nxt,{now.sc.fs+1,0}});
			}
			else if(dist[nxt]+1 == now.sc.fs+1){
				cnt[nxt][1]--;
				dp[nxt][1] += dp[now.fs][now.sc.sc];
				if(cnt[nxt][1] == 0)qq.push({nxt,{now.sc.fs+1,1}});
			}
			if(dp[nxt][0]>=mod)dp[nxt][0] -= mod;
			if(dp[nxt][1]>=mod)dp[nxt][1] -= mod;
		}
	}
	cout<<(dp[e][0]+dp[e][1])%mod<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

