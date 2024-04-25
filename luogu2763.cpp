#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2022;
const int inf = 1e9;
int n,p;//s:0,e:mxn-1,1 to p:type;p+1 to n+p:people

struct Edge{
	int to,cap,flow;
	Edge(){}
	Edge(int t,int c){
		to = t;
		cap = c;
		flow = 0;
	}
};

namespace DINIC{
	vector<int> paths[mxn];
	vector<Edge> edges;
	int ptr[mxn],lvl[mxn];
	queue<int> q;
	int tar;
	int add_edge(int a,int b,int c){
		int re = edges.size();
		paths[a].push_back(edges.size());
		edges.push_back(Edge(b,c));
		paths[b].push_back(edges.size());
		edges.push_back(Edge(a,0));
		return re;
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
				if(lvl[nxt] != -1||edges[eid].cap == edges[eid].flow)continue;
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
			int nxt = edges[eid].to;
			if(edges[eid].cap == edges[eid].flow)continue;
			if(lvl[nxt] != lvl[now]+1)continue;
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
	vector<int> ans[mxn];
	void getans(){
		for(int i = 1;i<=p;i++){
			for(auto &eid:paths[i]){
				if(edges[eid].flow == -1&&edges[eid].to!=mxn-1){
					ans[i].push_back(edges[eid].to-p);
				}
			}
		}
		for(int i = 1;i<=p;i++){
			cout<<i<<": ";
			for(auto &j:ans[i])cout<<j<<' ';cout<<'\n';
		}
		return;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>p>>n;
	int tar = 0;
	for(int i = 1;i<=p;i++){
		int k;
		cin>>k;
		tar += k;
		DINIC::add_edge(i,mxn-1,k);
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		DINIC::add_edge(0,i+p,1);
		//cout<<i<<":";
		while(k--){
			int tmp;
			cin>>tmp;
			DINIC::add_edge(i+p,tmp,1);
			//cout<<tmp<<',';
		}
		//cout<<'\n';
	}
	int tans = DINIC::GO(0,mxn-1);
	if(tans != tar){
		cout<<"No Solution!";
		return 0;
	}
	DINIC::getans();
	return 0;
}
