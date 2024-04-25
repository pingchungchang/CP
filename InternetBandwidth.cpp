#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int mxn = 505;
int s,t,m,n;
const int inf = 1e9;
int level[mxn],ptr[mxn];
int ccc = 0;
struct Edge{
	int from,to,cap;
	int flow;
	Edge(){
		from = to = cap = 0;
		flow = 0;
	}
	Edge(int ff,int tt,int cc){
		from = ff,to = tt,cap = cc;
		flow = 0;
	}
};
vector<Edge> edges;
vector<int> paths[mxn];
int pp = 0;
bool bfs(){
	queue<int> q;
	fill(level,level+n+1,-1);
	level[s] = 0;
	q.push(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto id:paths[now]){
			int nxt = edges[id].to;
			if(level[nxt] != -1)continue;
			if(edges[id].cap-edges[id].flow<=0)continue;
			level[nxt] = level[now]+1;
			q.push(nxt);
		}
	}
	if(level[t] != -1)return true;
	else return false;
}
int dfs(int now,int big){
	if(now == t)return big;
	if(big == 0)return 0;
	for(int &i = ptr[now];i<paths[now].size();i++){
		int nxt = edges[paths[now][i]].to;
		if(level[nxt]!=level[now]+1)continue;
		int tmp = dfs(nxt,min(big,edges[paths[now][i]].cap-edges[paths[now][i]].flow));
		if(!tmp)continue;
		edges[paths[now][i]].flow += tmp;
		edges[paths[now][i]^1].flow -= tmp;
		return tmp;
	}
	return 0;
}
 
void solve(){
    cin>>s>>t>>m;
    pp = 0;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
		edges.push_back(Edge(a,b,c));
		edges.push_back(Edge(b,a,c));
		paths[a].push_back(pp);
		paths[b].push_back(pp+1);
		pp += 2;
	}
	int ans = 0;
	while(bfs()){
		fill(ptr,ptr+n+1,0);
		ans += dfs(s,inf);
	}
    for(int i = 0;i<=n;i++)paths[i].clear();
    edges.clear();
    cout<<"Network "<<++ccc<<'\n';
    cout<<"The bandwidth is "<<ans<<'.'<<'\n';
    cout<<'\n';
    return;
}
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        if(n == 0)return 0;
        solve();
    }
    return 0;
}
