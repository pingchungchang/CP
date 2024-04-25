#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 505;
struct edge{
	int to,cost,flow,cap;
	edge(){
		to = cost = flow = cap = 0;
	}
	edge(int t,int c,int f,int ca){
		to = t,cost = c,flow = f,cap = ca;
	}
};

int n,m,k;
vector<edge> edges;
vector<int> paths[mxn];
bitset<mxn*2> vis;
int sum = 0;
int pre[mxn];
int dist[mxn];
vector<int> ans[mxn];

inline void add_edge(int a,int b){
	paths[a].push_back(edges.size());
	edges.push_back(edge(b,1,0,1));
	paths[b].push_back(edges.size());
	edges.push_back(edge(a,-1,0,0));
	return;
}

void SPFA(int st){
	fill(dist,dist+mxn,mxn*mxn);
	memset(pre,-1,sizeof(pre));
	queue<int> q;
	q.push(st);
	dist[st] = 0;
	pre[st] = -1;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &eid:paths[now]){
			if(edges[eid].cap-edges[eid].flow == 0)continue;
			int nxt = edges[eid].to;
			if(dist[nxt]>dist[now]+edges[eid].cost){
				dist[nxt] = dist[now]+edges[eid].cost;
				pre[nxt] = eid;
				q.push(nxt);
			}
		}
	}
	return;
}

vector<int> v;
void getans(int now){
	v.push_back(now);
	if(now == n)return;
	for(auto eid:paths[now]){
		if((eid&1)||vis[eid>>1]||edges[eid].cap-edges[eid].flow != 0)continue;
		vis[eid>>1] = true;
		getans(edges[eid].to);
		return;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		add_edge(a,b);
	}
	for(int i = 0;i<k;i++){
		SPFA(1);
		//cout<<i<<":";for(int j = 1;j<=n;j++)cout<<(pre[j]!= -1?edges[pre[j]^1].to:-1)<<' ';cout<<endl;
		if(pre[n] == -1){
			cout<<-1;
			return 0;
		}
		int now = n;
		while(pre[now] != -1){
			edges[pre[now]].flow++;
			edges[pre[now]^1].flow--;
			now = edges[pre[now]^1].to;
		}
		sum += dist[n];
	}
	cout<<sum<<'\n';
	for(int i = 0;i<k;i++){
		v.clear();
		getans(1);
		cout<<v.size()<<'\n';
		for(auto &j:v)cout<<j<<' ';cout<<'\n';
	}
	return 0;
}
