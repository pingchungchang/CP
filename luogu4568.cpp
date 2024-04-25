#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>

const int inf = 1e9;
const int mxn = 1e4+10;
const int mxc = 11;

int dist[mxn][mxc];
vector<pii> paths[mxn];
priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
int n,m,s,e,k;

void DIJKSTRA(){
	for(auto &i:dist)for(auto &j:i)j = inf;
	dist[s][0] = 0;
	pq.push(make_tuple(0,s,0));
	while(!pq.empty()){
		int t = get<2>(pq.top());
		int now = get<1>(pq.top());
		int d = get<0>(pq.top());
		pq.pop();
		if(d != dist[now][t])continue;
		for(auto nxt:paths[now]){
			if(dist[nxt.fs][t] > d+nxt.sc){
				dist[nxt.fs][t] = d+nxt.sc;
				pq.push(make_tuple(dist[nxt.fs][t],nxt.fs,t));
			}
			if(t<k&&dist[nxt.fs][t+1]>d){
				dist[nxt.fs][t+1] = d;
				pq.push(make_tuple(dist[nxt.fs][t+1],nxt.fs,t+1));
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	cin>>s>>e;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
		paths[b].push_back({a,c});
	}
	DIJKSTRA();
	cout<<*min_element(dist[e],dist[e]+k+1);
}
