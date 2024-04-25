#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
const int inf = 1e9;
int n,m;
struct Edge{
	int to,cap,flow;
	Edge(){}
	Edge(int t,int c){
		to = t,cap = c;
		flow = 0;
	}
};

namespace DINIC{
	vector<Edge> edges;
	vector<int> paths[mxn];
	int lvl[mxn];
	int ptr[mxn];
	queue<int> q;
	int s,e;
	void add_edge(int a,int b,int c){
		paths[a].push_back(edges.size());
		edges.push_back(Edge(b,c));
		paths[b].push_back(edges.size());
		edges.push_back(Edge(a,0));
		return;
	}
	bool bfs(){
		memset(lvl,-1,sizeof(lvl));
		lvl[s] = 0;
		q.push(s);
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			for(auto eid:paths[now]){
				int nxt = edges[eid].to;
				if(edges[eid].cap == edges[eid].flow)continue;
				if(lvl[nxt] != -1)continue;
				lvl[nxt] = lvl[now]+1;
				q.push(nxt);
			}
		}
		return lvl[e] != -1;
	}
	int dfs(int now,int f){
		if(now == e)return f;
		for(int &i = ptr[now];i<paths[now].size();i++){
			int eid = paths[now][i];
			int nxt = edges[eid].to;
			if(edges[eid].flow == edges[eid].cap)continue;
			if(lvl[nxt] != lvl[now]+1)continue;
			auto re = dfs(nxt,min(edges[eid].cap-edges[eid].flow,f));
			if(re){
				edges[eid].flow += re;
				edges[eid^1].flow -= re;
				return re;
			}
		}
		return 0;
	}
	int GO(int st,int ed){
		s = st,e = ed;
		int ans = 0;
		while(bfs()){
			memset(ptr,0,sizeof(ptr));
			int re;
			while(re = dfs(s,inf)){
				ans += re;
			}
		}
		return ans;
	}
	void getcut(){
		bfs();
		for(int i = 1;i<=m;i++){
			for(auto eid:paths[i]){
				if(edges[eid].cap == edges[eid].flow&&edges[eid].to){
					cout<<i<<' '<<edges[eid].to<<'\n';
				}
			}
		}
		return;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	for(int i = 1;i<=m;i++){
		DINIC::add_edge(0,i,1);
	}
	for(int i = m+1;i<=n;i++)DINIC::add_edge(i,n+m+1,1);
	int a,b;
	while(cin>>a>>b){
		if(a == -1&&b == -1)break;
		DINIC::add_edge(a,b,1);
	}
	int ans = DINIC::GO(0,n+m+1);
	cout<<ans<<'\n';
	DINIC::getcut();
	return 0;
}
