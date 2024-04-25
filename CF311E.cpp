#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int inf = 2e9;
const int sh = 1e6;
const int mxn = 2e4+10;
int n,m,g;
int arr[mxn],val[mxn];

namespace DINIC{
	struct Edge{
		int to,flow,cap;
		Edge(){}
		Edge(int t,int c){
			to = t,cap = c,flow = 0;
		}
	};
	vector<int> paths[mxn];
	vector<Edge> edges;
	int lvl[mxn],ptr[mxn];
	int tar;
	queue<int> q;
	void add_edge(int a,int b,int c){
		//cout<<a<<' '<<b<<' '<<(c>=inf?"inf":to_string(c-sh))<<'\n';
		//cout<<"add:"<<a<<' '<<b<<' '<<c<<endl;
		paths[a].push_back(edges.size());
		edges.push_back(Edge(b,c));
		paths[b].push_back(edges.size());
		edges.push_back(Edge(a,0));
	}

	int dfs(int now,int f){
		//cout<<now<<":"<<f<<endl;
		if(now == tar)return f;
		for(int &i = ptr[now];i<paths[now].size();i++){
			int eid = paths[now][i];
			if(edges[eid].cap-edges[eid].flow == 0)continue;
			int nxt = edges[eid].to;
			if(lvl[nxt] != lvl[now]+1)continue;
			auto re = dfs(nxt,min(f,edges[eid].cap-edges[eid].flow));
			if(re){
				edges[eid].flow += re;
				edges[eid^1].flow -= re;
				return re;
			}
		}
		return 0ll;
	}

	bool bfs(int s){
		memset(lvl,-1,sizeof(lvl));
		lvl[s] = 0;
		q.push(s);
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			for(auto &eid:paths[now]){
				if(edges[eid].cap-edges[eid].flow == 0)continue;
				int nxt = edges[eid].to;
				if(lvl[nxt] == -1){
					q.push(nxt);
					lvl[nxt] = lvl[now]+1;
				}
			}
		}
		return lvl[tar] != -1;
	}

	int GO(int s){
		int ans = 0;
		while(bfs(s)){
			//cout<<"BFS"<<endl;
			memset(ptr,0,sizeof(ptr));
			int re;
			while(re = dfs(s,inf)){
				ans += re;
			}
		}
		return ans;
	}

	int getcut(int s){
		bfs(s);
		int ans = 0;
		for(int i = 0;i<edges.size();i++){
			int now = edges[i^1].to;
			int nxt = edges[i].to;
			if(lvl[now] != -1&&lvl[nxt] == -1){
				if(edges[i].cap != 0)ans += edges[i].cap-sh;
			}
		}
		return ans;
	}
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>g;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>val[i];
	for(int i = 1;i<=n;i++){
		if(arr[i])DINIC::add_edge(i,n+m+1,val[i]);
		else DINIC::add_edge(0,i,val[i]);
	}
	//s:0 e:1
	int tans = 0;
	for(int i = 1;i<=m;i++){
		int w,k,sx;
		cin>>sx>>w>>k;
		tans += w;
		int tmp[k];
		for(auto &j:tmp)cin>>j;
		int f;
		cin>>f;
		if(f)w += g;
		if(sx)DINIC::add_edge(i+n,n+m+1,w);
		else DINIC::add_edge(0,i+n,w);
		for(auto &j:tmp){
			if(!sx)DINIC::add_edge(i+n,j,inf);
			else DINIC::add_edge(j,i+n,inf);
		}
	}
	DINIC::tar = n+m+1;
	cout<<tans-DINIC::GO(0);
}
