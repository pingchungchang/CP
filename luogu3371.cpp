#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll inf = 1e18;
const int mxn = 1e4+10;
vector<pll> paths[mxn];
ll dist[mxn];

void DIJKSTRA(int s){
	for(auto &i:dist)i = INT_MAX;
	dist[s] = 0;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	pq.push({0ll,s});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.fs != dist[now.sc])continue;
		for(auto nxt:paths[now.sc]){
			if(dist[nxt.fs]>dist[now.sc]+nxt.sc){
				dist[nxt.fs] = dist[now.sc]+nxt.sc;
				pq.push({dist[nxt.fs],nxt.fs});
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,s;
	cin>>n>>m>>s;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
	}
	DIJKSTRA(s);
	for(int i = 1;i<=n;i++){
		cout<<dist[i]<<' ';
	}
	return 0;
}
