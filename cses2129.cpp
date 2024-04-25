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

const int mxn = 420;
const int inf = 1e9+10;
vector<edge> edges;
vector<int> paths[mxn];
int dist[mxn],pre[mxn];
int n;

void addedge(int from,int to,int cap,int cost){
	paths[from].push_back(edges.size());
	edges.push_back(edge(to,cap,cost));
	paths[to].push_back(edges.size());
	edges.push_back(edge(from,0,-cost));
	return;
}

void SPFA(int now){
	fill(dist,dist+mxn,inf);
	pre[now] = 0;
	dist[now] = 0;
	queue<int> q;
	q.push(now);
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
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			int k;
			cin>>k;
			addedge(i,n+j,1,k);
		}
	}
	for(int i = 1;i<=n;i++){
		addedge(0,i,1,0);
		addedge(i+n,n*2+1,1,0);
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		//cout<<i<<endl;
		SPFA(0);
		//for(int j = 0;j<=n*2+1;j++)cout<<dist[i]<<' ';cout<<endl;
		assert(dist[n*2+1] != inf);
		ans += dist[n*2+1];
		int now = n*2+1;
		while(now){
			edges[pre[now]].cap--;
			edges[pre[now]^1].cap++;
			now = edges[pre[now]^1].to;
		}
	}
	cout<<ans<<'\n';
	for(int i = 1;i<=n;i++){
		for(auto &eid:paths[i]){
			if(edges[eid].to&&!edges[eid].cap){
				cout<<i<<' '<<edges[eid].to-n<<'\n';
			}
		}
	}
}
