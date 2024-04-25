#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 505;
const int inf = mxn*mxn;

struct Edge{
	int to,cap,flow;
	Edge(){}
	Edge(int tt,int cc){
		to = tt,cap = cc;
		flow = 0;
	}
};

struct DINIC{
	vector<Edge> edges;
	vector<int> paths[mxn*2];
	int src,tml;
	int level[mxn*2],ptr[mxn*2];
	queue<int> q;

	void add_edge(int a,int b,int c){
		paths[a].push_back(edges.size());
		edges.push_back(Edge(b,c));
		paths[b].push_back(edges.size());
		edges.push_back(Edge(a,0));
	}

	bool bfs(){
		memset(level,-1,sizeof(level));
		level[src] = 0;
		q.push(src);
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			for(auto &eid:paths[now]){
				int nxt = edges[eid].to;
				if(edges[eid].cap-edges[eid].flow == 0||level[nxt] != -1)continue;
				level[nxt] = level[now]+1;
				q.push(nxt);
			}
		}
		return level[tml] != -1;
	}

	int dfs(int now,int f){
		if(now == tml)return f;
		for(int &i = ptr[now];i<paths[now].size();i++){
			int eid = paths[now][i];
			int nxt = edges[eid].to;
			if(edges[eid].cap-edges[eid].flow == 0||level[nxt] != level[now]+1)continue;
			int tmp = dfs(nxt,min(f,edges[eid].cap-edges[eid].flow));
			assert(tmp>=0);
			if(tmp){
				edges[eid].flow += tmp;
				edges[eid^1].flow -= tmp;
				return tmp;
			}
		}
		return 0;
	}

	int flow(int a,int b){
		src = a,tml = b;
		int ans = 0;
		while(bfs()){
			memset(ptr,0,sizeof(ptr));
			int re;
			while(re = dfs(src,inf)){
				ans += re;
			}
		}
		return ans;
	}
};

pii arr[mxn];
int n,c;
DINIC graph;
int ans = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>c;
	for(int i = 1;i<=n;i++)cin>>arr[i].fs;
	for(int i = 1;i<=n;i++)cin>>arr[i].sc;
	for(int i = 1;i<=n;i++){
		int tmp;
		cin>>tmp;
		ans += min(tmp,arr[i].fs);
		arr[i].fs -= tmp;
	}
	for(int i = 1;i<=n;i++){
		int tmp;
		cin>>tmp;
		ans += min(tmp,arr[i].sc);
		arr[i].sc -= tmp;
	}
	for(int i = 1;i<=n;i++){
		if(arr[i].fs<0)graph.add_edge(i,mxn*2-1,-arr[i].fs);
		if(arr[i].sc<0)graph.add_edge(i+mxn,mxn*2-1,-arr[i].sc);
		if(arr[i].fs>=0)graph.add_edge(0,i,arr[i].fs);
		if(arr[i].sc>=0)graph.add_edge(0,i+mxn,arr[i].sc);
	}
	for(int i = 1;i<=n;i++){
		/*
		if(arr[i].fs>=0){
			for(int j = i+1;j<=n;j++){
				if(arr[j].sc<0)graph.add_edge(i,j+mxn,c);
			}
		}
		if(arr[i].sc>=0){
			for(int j = i+1;j<=n;j++){
				if(arr[j].fs<0)graph.add_edge(i+mxn,j,c);
			}
		}
	   */

		for(int j = i+1;j<=n;j++){
			graph.add_edge(i+mxn,j,c);
			graph.add_edge(i,j+mxn,c);
		}
	}
	int tmp = graph.flow(0,mxn*2-1);
	ans += tmp;
	cout<<ans;
}
