#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int inf = 4e9+10;

struct edge{
	int to,cap,flow;
	edge(){
		to = cap = flow = 0;
	}
	edge(int dest,int c){
		cap = c;
		to = dest;
		flow = 0;
	}
};

const int mxn = 110;
vector<int> paths[mxn*2];
vector<edge>edges;
bitset<mxn> in,out;
int level[mxn*2],ptr[mxn*2];
int n;

void add_edge(int a,int b,int c){
	paths[a].push_back(edges.size());
	edges.push_back(edge(b,c));
	paths[b].push_back(edges.size());
	edges.push_back(edge(a,0));
	return;
}

bool bfs(){
	memset(level,-1,sizeof(level));
	queue<int> q;
	q.push(0);
	level[0] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto eid:paths[now]){
			if(edges[eid].cap-edges[eid].flow == 0)continue;
			if(level[edges[eid].to] != -1)continue;
			level[edges[eid].to] = level[now]+1;
			q.push(edges[eid].to);
		}
	}
	return level[n*2+1] != -1;
}

int dfs(int now,int big){
	if(now == n*2+1)return big;
	if(!big)return 0;
	for(int &i = ptr[now];i<paths[now].size();i++){
		auto eid = paths[now][i];
		int nxt = edges[eid].to;
		if(edges[eid].cap-edges[eid].flow==0)continue;
		if(level[nxt] != level[now]+1)continue;
		int re = dfs(nxt,min(big,edges[eid].cap-edges[eid].flow));
		if(!re)continue;
		edges[eid].flow+=re;
		edges[eid^1].flow -= re;
		return re;
	}
	return 0;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		add_edge(i,i+n,k);
	}
	int m;
	cin>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		add_edge(a+n,b,inf);
		in[b] = true;
		out[a] = true;
	}
	for(int i = 1;i<=n;i++){
		if(!in[i])add_edge(0,i,inf);
		if(!out[i])add_edge(i+n,n*2+1,inf);
	}
	/*
	for(int i = 0;i<=n;i++){
		for(auto &j:paths[i])cout<<i<<' '<<edges[j].to<<' '<<edges[j].cap<<endl;
	}

   */
	int ans = 0;
	bfs();
	while(bfs()){
		memset(ptr,0,sizeof(ptr));
		int re;
		while(re = dfs(0,inf))ans+=re;
	}
	cout<<ans;
}
