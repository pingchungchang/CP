#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
const ll inf = 6e18;
vector<pll> paths[mxn];
int n,m;
ll dist[2][mxn];
bool done[2][mxn];

void DIJKSTRA(int s){
	fill(dist[0],dist[0]+n+1,inf);
	fill(dist[1],dist[1]+n+1,inf);
	memset(done,0,sizeof(done));
	dist[0][s] = 0;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	pq.push({0LL,s});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(done[1][now.sc])continue;
		if(done[0][now.sc]&&dist[0][now.sc] == now.fs)continue;
		if(!done[0][now.sc])done[0][now.sc] = true;
		else done[1][now.sc] = true;
		for(auto nxt:paths[now.sc]){
			ll d = nxt.sc+now.fs;
			if(d<dist[0][nxt.fs]){
				swap(dist[0][nxt.fs],dist[1][nxt.fs]);
				dist[0][nxt.fs] = d;
				pq.push({dist[0][nxt.fs],nxt.fs});
			}
			else if(d<dist[1][nxt.fs]&&d != dist[0][nxt.fs]){
				dist[1][nxt.fs] = d;
				pq.push({dist[1][nxt.fs],nxt.fs});
			}
		}
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++)paths[i].clear();
	cin>>n>>m;
	ll s,e;
	cin>>s>>e;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
	}
	DIJKSTRA(s);
	assert(dist[1][e] != dist[0][e]);
	cout<<dist[1][e]-dist[0][e]<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
