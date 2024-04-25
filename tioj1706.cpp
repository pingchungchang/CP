#include <bits/stdc++.h>
using namespace std;

//#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ll int


struct Edge{
	ll a,b,to;
	Edge(){}
	Edge(ll ta,ll tb,ll tt){
		a = ta,b = tb,to = tt;
	}
	ll operator()(ll k){
		return a*k+b;
	}
};

const ll mxn = 1e5+10;
const ll inf = 1e9+10;
ll dist[mxn];
ll n,m,d;
vector<Edge> paths[mxn];
priority_queue<pll,vector<pll>,greater<pll>> pq;

inline ll DIJKSTRA(ll s,ll e,ll dt){
	fill(dist,dist+n+1,inf);
	dist[s] = 0;
	pq.push(make_pair(dist[s],s));
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.fs != dist[now.sc])continue;
		for(auto nxt:paths[now.sc]){
			if(dist[nxt.to]>dist[now.sc]+nxt(dt)){
				dist[nxt.to] = dist[now.sc]+nxt(dt);
				pq.push(make_pair(dist[nxt.to],nxt.to));
			}
		}
	}
	return dist[e];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int s,e;
	cin>>n>>m>>s>>e>>d;
	for(int i = 0;i<m;i++){
		Edge ta,tb;
		cin>>tb.to>>ta.to>>ta.b>>ta.a>>tb.b>>tb.a;
		paths[tb.to].push_back(ta);
		paths[ta.to].push_back(tb);
	}
	int ans = inf;
	cout<<min(DIJKSTRA(s,e,0)+DIJKSTRA(e,s,0),DIJKSTRA(s,e,d-1)+DIJKSTRA(e,s,d-1));
}
