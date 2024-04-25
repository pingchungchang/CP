#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

struct edge{
	int to,cap;
	ll cost;
	edge(int a,int b,ll c){
		to = a,cap = b,cost = c;
	}
};
const int mxn = 220;
const ll inf = 1e18;
vector<edge> edges;
vector<int> paths[mxn];
ll dist[mxn],pre[mxn];
int n;

inline void addedge(int a,int b,int cap,int cost){
	paths[a].push_back(edges.size());
	edges.push_back(edge(b,cap,cost));
	paths[b].push_back(edges.size());
	edges.push_back(edge(a,0,-cost));
	return;
}

inline void SPFA(int s){
	fill(dist,dist+n*2+2,inf);
	pre[s] = 0;
	queue<int> q;
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &eid:paths[now]){
			if(!edges[eid].cap)continue;
			int nxt = edges[eid].to;
			if(dist[nxt]>dist[now]+edges[eid].cost){
				dist[nxt] = dist[now]+edges[eid].cost;
				pre[nxt] = eid;
				q.push(nxt);
			}
		}
	}
	return;
}

void solve(){
	if(!n)exit(0);
	edges.clear();
	for(auto &i:paths)i.clear();
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			int k;
			cin>>k;
			k = max(0,k);
			addedge(i,j+n,1,-k);
		}
		addedge(0,i,1,0);
		addedge(i+n,n*2+1,1,0);
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		SPFA(0);
		ans += dist[n*2+1];
		int now = n*2+1;
		while(now){
			edges[pre[now]].cap--;
			edges[pre[now]^1].cap++;
			now = edges[pre[now]^1].to;
		}
	}
	cout<<-ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
