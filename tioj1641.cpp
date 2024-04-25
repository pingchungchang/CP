#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld double


const ld eps = 1e-6;
const int mxn = 1e4+10;
priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> pq;
vector<pair<ll,ld>> paths[mxn];
ld dist[mxn];
bitset<mxn> vis;

main(){
	int n,m,s,e;
	for(auto &i:dist)i = 1e18;
	scanf("%lld%lld%lld%lld",&n,&m,&s,&e);
	for(int i = 0;i<m;i++){
		ll a,b;
		ld c;
		scanf("%lld%lld%lf",&a,&b,&c);
		paths[a].push_back({b,(ld)log10(c+1)});
	}
	dist[s] = 0;
	pq.push({dist[s],s});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(vis[now.sc])continue;
		vis[now.sc] = true;
		for(auto nxt:paths[now.sc]){
			if(dist[nxt.fs]>dist[now.sc]+nxt.sc){
				dist[nxt.fs] = dist[now.sc]+nxt.sc;
				pq.push(make_pair(dist[nxt.fs],nxt.fs));
			}
		}
	}
	ll x = floor(dist[e]);
	dist[e] -= x;
	printf("%.2fe+%03lld\n",pow(10,dist[e]),x);
}
