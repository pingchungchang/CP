#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 320;
const int inf = 1e9;
int n,m;

struct Edge{
	int to,cap,flow;
	Edge(){}
	Edge(int t,int c){
		to = t,cap = c,flow = 0;
	}
};


namespace DINIC{
	vector<int> paths[mxn];
	vector<Edge> edges;
	int lvl[mxn],ptr[mxn];
	int tar;
	queue<int> q;
	void add_edge(int a,int b,int c){
		paths[a].push_back(edges.size());
		edges.push_back(Edge(b,c));
		paths[b].push_back(edges.size());
		edges.push_back(Edge(a,0));
		return;
	}
	bool bfs(int s,int e){
		memset(lvl,-1,sizeof(lvl));
		lvl[s] = 0;
		q.push(s);
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			for(auto &eid:paths[now]){
				int nxt = edges[eid].to;
				if(edges[eid].cap == edges[eid].flow||lvl[nxt] != -1)continue;
				lvl[nxt] = lvl[now]+1;
				q.push(nxt);
			}
		}
		return lvl[e] != -1;
	}
	int dfs(int now,int f){
		if(now == tar)return f;
		for(int &i = ptr[now];i<paths[now].size();i++){
			int eid = paths[now][i];
			int nxt = edges[eid].to;
			if(lvl[nxt] != lvl[now]+1||edges[eid].cap == edges[eid].flow)continue;
			int re = dfs(nxt,min(f,edges[eid].cap-edges[eid].flow));
			if(re){
				edges[eid].flow += re;
				edges[eid^1].flow -= re;
				return re;
			}
		}
		return 0;
	}
	int GO(int s,int e){
		tar = e;
		int ans = 0;
		while(bfs(s,e)){
			memset(ptr,0,sizeof(ptr));
			int re;
			while(re = dfs(s,inf))ans += re;
		}
		return ans;
	}
	int chain[mxn];
	int dsu[mxn];
	int root(int k){
		return k == dsu[k]?k:dsu[k] = root(dsu[k]);
	}
	void getans(){
		for(int i = 1;i<=n;i++)dsu[i] = i;
		for(int i = 1;i<=n;i++){
			for(auto &eid:paths[i]){
				if(edges[eid].flow == 0)continue;
				int nxt = edges[eid].to;
				if(nxt<=n)continue;
				nxt -= n;
				chain[i] = nxt;
				dsu[root(nxt)] = root(i);
			}
		}
		for(int i = 1;i<=n;i++){
			if(dsu[i] != i)continue;
			int now = i;
			while(now){
				cout<<now<<' ';
				now = chain[now];
			}
			cout<<'\n';
		}
		return;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		DINIC::add_edge(0,i,1);
		DINIC::add_edge(i+n,mxn-1,1);
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		DINIC::add_edge(a,b+n,1);
	}
	int ans = DINIC::GO(0,mxn-1);
	DINIC::getans();
	cout<<n-ans;
	return 0;
}
