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
const ll inf = 1e14+10;
const int mxn = 1e5+10;
vector<pll> paths[mxn];
int main(){
	io
	int n,m,s,e;
	cin>>n>>m>>s>>e;
	for(int i= 0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		paths[u].push_back({v,w});
	}
	priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;
	ll dist[n+1][2];
	memset(dist,inf,sizeof(dist));
	dist[s][0] = dist[s][1] = 0;
	pq.push({0,{s,0}});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(dist[now.sc.fs][now.sc.sc] != now.fs)continue;
		for(auto nxt:paths[now.sc.fs]){
			if(now.sc.sc == 0&&now.fs<dist[nxt.fs][1]){
				dist[nxt.fs][1] = now.fs;
				pq.push({now.fs,{nxt.fs,1}});
			}
			if(now.fs+nxt.sc<dist[nxt.fs][now.sc.sc]){
				dist[nxt.fs][now.sc.sc] = now.fs+nxt.sc;
				pq.push({now.fs+nxt.sc,{nxt.fs,now.sc.sc}});
			}
		}
	}
	
	ll ans= min(dist[e][0],dist[e][1]);
	if(ans >=inf)cout<<-1;
	else cout<<ans;
}

