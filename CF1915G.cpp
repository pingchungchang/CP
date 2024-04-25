#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll inf = 4e18;
const ll mxn = 1010;
ll dist[mxn*mxn];
priority_queue<pll,vector<pll>,greater<pll>> pq;
vector<pii> paths[mxn*mxn],g[mxn];
int cost[mxn];
ll n,m;

inline void DIJKSTRA(ll s){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)dist[i+j*mxn] = inf;
	}
	dist[s] = 0;
	pq.push(make_pair(dist[s],s));
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.fs != dist[now.sc])continue;
		for(auto nxt:paths[now.sc]){
			if(dist[nxt.fs]>now.fs+nxt.sc){
				dist[nxt.fs] = now.fs+nxt.sc;
				pq.push(make_pair(dist[nxt.fs],nxt.fs));
			}
		}
	}
	return;
}

void solve(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)paths[i+mxn*j].clear();
		g[i].clear();
	}
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i = 1;i<=n;i++)cin>>cost[i];
	for(int i = 1;i<=n;i++){
		for(auto &nxt:g[i]){
			for(int sm = 1;sm<=n;sm++){
				if(cost[sm]<=cost[nxt.fs])paths[i+mxn*sm].push_back(make_pair(nxt.fs+mxn*sm,cost[sm]*nxt.sc));
				else paths[i+mxn*sm].push_back(make_pair(nxt.fs+mxn*nxt.fs,cost[sm]*nxt.sc));
			}
		}
	}
	DIJKSTRA(1+mxn*1);
	ll ans = inf;
	/*
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)cout<<(dist[i+mxn*j]>=inf?-1:dist[i+mxn*j])<<' ';cout<<endl;
	}

   */
	for(int i = 1;i<=n;i++){
		ans = min(ans,dist[n+mxn*i]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
