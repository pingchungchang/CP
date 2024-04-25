#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

struct Edge{
	int to,cap,flow;
	Edge(){}
	Edge(int t,int c){
		to = t,cap = c,flow = 0;
	}
};
const int mxn = 20100;
int n,m,num;
int tlim = 0.95*CLOCKS_PER_SEC;
const int inf = 10000;

namespace DINIC{
	vector<int> paths[mxn];
	vector<Edge> edges;
	int lvl[mxn],ptr[mxn];
	queue<int> q;
	int tar;
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
				if(edges[eid].flow == edges[eid].cap ||lvl[nxt] != -1)continue;
				q.push(nxt);
				lvl[nxt] = lvl[now]+1;
			}
		}
		return lvl[e]!=-1;
	}

	int dfs(int now,int f){
		if(now == tar)return f;
		for(int &i = ptr[now];i<paths[now].size();i++){
			int eid = paths[now][i];
			if(edges[eid].flow == edges[eid].cap)continue;
			if(lvl[edges[eid].to] != lvl[now]+1)continue;
			int re = dfs(edges[eid].to,min(f,edges[eid].cap-edges[eid].flow));
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
}

vector<int> route[30];
int cap[30];
int pt[30];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>num;
	for(int i = 1;i<=m;i++){
		cin>>cap[i];
		int k;
		cin>>k;
		while(k--){
			int tmp;
			cin>>tmp;
			if(tmp == -1)tmp = n+1;
			route[i].push_back(tmp);
		}
	}
	DINIC::add_edge(n+1,mxn-1,inf);
	int st = clock();
	int sum = 0;
	for(int i = 1;(i+1)*(n+2)<mxn;i++){
		int sh = (n+2)*i;
		for(int j = 0;j<=n+1;j++){
			DINIC::add_edge(sh+j-(n+2),sh+j,inf);
		}
		DINIC::add_edge(sh+n+1,mxn-1,inf);
		for(int j = 1;j<=m;j++){
			pt[j]++;
			if(pt[j] == route[j].size()){
				DINIC::add_edge(sh-(n+2)+route[j][pt[j]-1],sh+route[j][0],cap[j]);
				pt[j] = 0;
			}
			else{
				DINIC::add_edge(sh-(n+2)+route[j][pt[j]-1],sh+route[j][pt[j]],cap[j]);
			}
		}
		sum += DINIC::GO(0,mxn-1);
		//cout<<sum<<endl;
		if(sum>=num){
			cout<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
