#include <bits/stdc++.h>
using namespace std;

const int mxn = 505;
struct Edge{
	int to,cap,flow;
	Edge(){
		to = cap = flow = 0;
	}
	Edge(int tt,int cc){
		to = tt,cap = cc;
		flow = 0;
	}
};
Edge edges[mxn*4];
int pp =  0;
int ptr[mxn],level[mxn];
const int inf = 1e9;
int n,m;
vector<int> paths[mxn];
bool bfs(){
	fill(level,level+mxn,-1);
	level[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto id:paths[now]){
			if(edges[id].cap-edges[id].flow<=0)continue;
			int nxt = edges[id].to;
			if(level[nxt] != -1)continue;
			level[nxt] = level[now]+1;
			q.push(nxt);
		}
	}
	return level[n] != -1;
}

int dfs(int now,int big){
	if(now == n)return big;
	if(!big)return 0;
	for(int &i = ptr[now];i<paths[now].size();i++){
		int id = paths[now][i];
		if(edges[id].cap-edges[id].flow<=0)continue;
		int nxt = edges[id].to;
		if(level[nxt] != level[now]+1)continue;
		int tmp = dfs(nxt,min(big,edges[id].cap-edges[id].flow));
		if(!tmp)continue;
		edges[id].flow += tmp;
		edges[id^1].flow -= tmp;
		return tmp;
	}
	return 0;
}
vector<int> v;
bool getans(int now){
	v.push_back(now);
	if(now == 1){
		cout<<v.size()<<'\n';
		for(int i = v.size()-1;i>=0;i--)cout<<v[i]<<' ';cout<<'\n';
		return true;
	}
	for(auto id:paths[now]){
		if(id&1){
			if(edges[id].cap-edges[id].flow>0){
				// cout<<now<<' '<<edges[id].to<<' '<<edges[id].cap-edges[id].flow<<endl;
				edges[id].flow++;
				if(getans(edges[id].to)){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(pp);
		paths[b].push_back(pp+1);
		edges[pp] = Edge(b,1);
		edges[pp^1] = Edge(a,0);
		pp+=2;
	}
	int ans = 0;
	while(bfs()){
		fill(ptr,ptr+mxn,0);
		int re = 0;
		while(re = dfs(1,inf))ans += re;
	}
	cout<<ans<<'\n';
	for(int i = 0;i<ans;i++){
		v.clear();
		getans(n);
	}
}