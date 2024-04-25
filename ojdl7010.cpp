#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const ll inf = 2e18;
int main(){
	io
	int n,m;
	cin>>n>>m;
	vector<vector<pll>> paths(n+1);
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
		paths[b].push_back({a,c});
	}
	vector<ll> dist(n+1,inf);
	dist[1] = 0;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	pq.push({0,1});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(dist[now.sc] != now.fs)continue;
		for(auto nxt:paths[now.sc]){
			if(now.fs+nxt.sc<dist[nxt.fs]){
				dist[nxt.fs] = now.fs+nxt.sc;
				pq.push({dist[nxt.fs],nxt.fs});
			}
		}
	}
	for(int i = 1;i<=n;i++)cout<<dist[i]<<'\n';
	return 0;
}

