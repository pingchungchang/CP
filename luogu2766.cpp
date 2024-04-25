#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int short


const int inf = 20000;
const int mxn = 1010;
int n;
int arr[mxn];
int dp[mxn];

struct Edge{
	int to,cap,flow;
	Edge(){}
	Edge(int t,int c){
		to = t,cap = c;
		flow = 0;
	}
};

namespace DINIC{
	vector<int> paths[mxn];
	vector<Edge> edges;
	queue<int> q;
	int tar;
	int lvl[mxn],ptr[mxn];
	int add_edge(int a,int b,int c){
		paths[a].push_back(edges.size());
		int re = edges.size();
		edges.push_back(Edge(b,c));
		paths[b].push_back(edges.size());
		edges.push_back(Edge(a,0));
		return re;
	}
	bool bfs(int s,int e){
		memset(lvl,-1,sizeof(lvl));
		q.push(s);
		lvl[s] = 0;
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			for(auto &eid:paths[now]){
				int nxt = edges[eid].to;
				if(edges[eid].flow == edges[eid].cap||lvl[nxt] != -1)continue;
				q.push(nxt);
				lvl[nxt] = lvl[now]+1;
			}
		}
		return lvl[e] != -1;
	}
	int dfs(int now,int f){
		if(now == tar)return f;
		for(int &i = ptr[now];i<paths[now].size();i++){
			int eid = paths[now][i];
			if(edges[eid].cap == edges[eid].flow)continue;
			int nxt = edges[eid].to;
			if(lvl[nxt] != lvl[now]+1)continue;
			int re = dfs(nxt,min((short)(edges[eid].cap-edges[eid].flow),f));
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
	void clean(){
		for(auto &i:edges)i.flow = 0;
		return;
	}
	void init(){
		for(auto &i:paths)i.clear();
		edges.clear();
		return;
	}
}

queue<int> q;
int idx[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		DINIC::add_edge(a,b,c);
	}
	cout<<DINIC::GO(1,n);return 0;

	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++){
		dp[i] = 1;
		for(int j = i-1;j>=1;j--){
			if(arr[j]<=arr[i])dp[i] = max(dp[i],short(dp[j]+1));
		}
		idx[i] = DINIC::add_edge(i*2,i*2+1,1);
	}
	int lis = *max_element(dp+1,dp+n+1);
	for(int i = 1;i<=n;i++){
		if(dp[i] == lis)q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(int j = now-1;j>=1;j--){
			if(arr[j]<=arr[now]&&dp[j] == dp[now]-1){
				DINIC::add_edge(j*2+1,now*2,inf);
				q.push(j);
			}
		}
		if(dp[now] == 1){
			DINIC::add_edge(0,now*2,inf);
		}
		if(dp[now] == lis){
			DINIC::add_edge(now*2+1,mxn-1,inf);
		}
	}
	int ans1 = DINIC::GO(0,mxn-1);
	//DINIC::clean();
	DINIC::add_edge(1*2,1*2+1,inf);
	DINIC::add_edge(n*2,n*2+1,inf);
	/*

   */
	for(int i = 0;i<DINIC::edges.size();i+=2){
		if(DINIC::edges[i].to == n*2&&DINIC::edges[i^1].to == 1*2+1){
			DINIC::edges[i].cap = 1;
			break;
		}
	}
	int ans2 = ans1+DINIC::GO(0,mxn-1);
	if(lis == 1)ans2 = n;
	cout<<lis<<'\n'<<ans1<<'\n'<<ans2<<'\n';
	return 0;
}
