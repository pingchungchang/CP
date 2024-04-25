#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 220;
const int sh = 110;
const int inf = 1e6+10;

struct Edge{
	int cap,to,cost;
	Edge(){}
	Edge(int a,int b,int c){
		to = a,cap = b,cost = c;
	}
};


int n,d,r;
vector<Edge> edges;
vector<int> paths[mxn];
int dist[mxn],pre[mxn];
int arr[mxn],brr[mxn];
queue<int> q;
bitset<mxn> inq;

void add_edge(int a,int b,int c){
	paths[a].push_back(edges.size());
	edges.push_back(Edge(b,1,c));
	paths[b].push_back(edges.size());
	edges.push_back(Edge(a,0,-c));
	return;
}

int GO(){
	for(auto &i:dist)i = inf;
	memset(pre,-1,sizeof(pre));
	dist[0] = 0;
	inq[0] = true;
	q.push(0);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		inq[now] = false;
		for(auto &eid:paths[now]){
			int nxt = edges[eid].to;
			if(!edges[eid].cap)continue;
			if(dist[nxt]>dist[now]+edges[eid].cost){
				dist[nxt] = dist[now]+edges[eid].cost;
				pre[nxt] = eid;
				if(!inq[nxt]){
					q.push(nxt);
					inq[nxt] = true;
				}
			}
		}
	}
	/*
	for(int i = 1;i<=n;i++)cout<<dist[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<dist[i+sh]<<' ';cout<<endl;
	cout<<dist[0]<<' '<<dist[mxn-1];cout<<endl;

   */
	assert(dist[mxn-1]<inf);
	int now = mxn-1;
	while(now){
		int eid = pre[now];
		edges[eid].cap--;
		edges[eid^1].cap++;
		now = edges[eid^1].to;
	}
	return dist[mxn-1];
}

void solve(){
	edges.clear();
	for(auto &i:paths)i.clear();
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>brr[i];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			int s = arr[i]+brr[j];
			s = max(0,s-d);
			add_edge(i,j+sh,s);
		}
		add_edge(0,i,0);
		add_edge(i+sh,mxn-1,0);
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		int re = GO();
		//cout<<re<<',';
		ans += re;
	}
	cout<<ans*r<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>d>>r)solve();
}
