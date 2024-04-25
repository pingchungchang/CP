#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 5030;
const int inf = 1e9;

vector<int> paths[mxn];
vector<pii> edges;
int dist[mxn];
int n,m;
bitset<mxn> inq;
deque<int> q;
priority_queue<pii,vector<pii>,greater<pii>> pq;

void SPFA(int s,int ban,int tar){
	q.clear();
	fill(dist,dist+n+1,inf);
	dist[s] = 0;
	for(int i = 1;i<=n;i++){
		q.push_back(i);
		inq[i] = true;
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop_front();
		inq[now] = false;
		for(auto eid:paths[now]){
			if((eid>>1) == ban)continue;
			int nxt = edges[eid].fs;
			int w = edges[eid].sc;
			if(dist[nxt]>dist[now]+w){
				dist[nxt] = dist[now]+w;
				if(!inq[nxt]){
					inq[nxt] = true;
					q.push_back(nxt);
				}
			}
		}
	}
	return;
}

void DIJKSTRA(int s,int ban,int tar){
	while(!pq.empty())pq.pop();
	fill(dist,dist+n+1,inf);
	dist[s] = 0;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.fs != dist[now.sc])continue;
		if(now.fs>dist[tar])return;
		for(auto eid:paths[now.sc]){
			if((eid>>1) == ban)continue;
			int nxt = edges[eid].fs,w = edges[eid].sc;
			if(dist[nxt]>dist[now.sc]+w){
				dist[nxt] = dist[now.sc]+w;
				pq.push(make_pair(dist[nxt],nxt));
			}
		}
	}
	return;
}

void add_edge(int a,int b,int c,int d){
	paths[a].push_back(edges.size());
	edges.push_back(make_pair(b,c));
	paths[b].push_back(edges.size());
	edges.push_back(make_pair(a,d));
	return;
}

pii src[mxn];

void DIJ2(){
	priority_queue<pii,vector<pii>,greater<pii>> pq;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int st = clock();
	for(int i = 1;i<=m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		add_edge(a,b,c,d);
	}
	int ans = 2e9;
	DIJ2();
	/*
	srand(time(NULL));
	random_shuffle(paths[1].begin(),paths[1].end());
	int lim = 1.7*CLOCKS_PER_SEC;
	for(auto &eid:paths[1]){
		SPFA(1,eid>>1,edges[eid].fs);
		ans = min(ans,dist[edges[eid].fs]+edges[eid^1].sc);
		SPFA(edges[eid].fs,eid>>1,1);
		ans = min(ans,dist[1]+edges[eid].sc);
		if(clock()-st>=lim)break;
	}
	cout<<ans;
   */
}

