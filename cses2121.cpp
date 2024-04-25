#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

struct edge{
	int to,cap,cost;
	edge(int a,int b,int c){
		to = a,cap = b,cost = c;
	}
};

const int mxn = 505;
const ll inf = 1e9;
int n,m,tar;
vector<edge> edges;
vector<int> paths[mxn];
ll dist[mxn],pre[mxn];

void SPFA(int s){
	queue<int> q;
	fill(dist,dist+n+1,inf);
	fill(pre,pre+n+1,inf);
	pre[s] = 0;
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &eid:paths[now]){
			if(edges[eid].cap == 0)continue;
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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>tar;
	for(int i = 0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		paths[a].push_back(edges.size());
		edges.push_back(edge(b,c,d));
		paths[b].push_back(edges.size());
		edges.push_back(edge(a,0,-d));
	}
	ll ans = 0;
	for(int i = 0;i<tar;i++){
		SPFA(1);
		if(dist[n] >= inf){
			cout<<"-1";
			return 0;
		}
		ans += dist[n];
		int now = n;
		while(now != 1){
			edges[pre[now]].cap--;
			edges[pre[now]^1].cap++;
			now = edges[pre[now]^1].to;
		}
	}
	cout<<ans;
}
