#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 4e5+10;
const ll inf = 1e18;
vector<pll> paths[mxn];
vector<tuple<ll,ll,ll>> edges;
ll dist[mxn];
ll dsu[mxn],sz[mxn];
ll ans[mxn];
vector<tuple<int,int,int>> req[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

inline void onion(int a,int b,ll w){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	if(req[a].size()<req[b].size())swap(req[a],req[b]);
	sz[a] += sz[b];
	dsu[b] = a;
	while(!req[b].empty()){
		int ta = get<0>(req[b].back()),tb = get<1>(req[b].back());
		if(root(ta) == root(tb))ans[get<2>(req[b].back())] = min(ans[get<2>(req[b].back())],w);
		else req[a].push_back(req[b].back());
		req[b].pop_back();
	}
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,k,q;
	cin>>n>>m>>k>>q;
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
		paths[b].push_back({a,c});
	}
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	fill(dist,dist+mxn,inf);
	for(int i = 1;i<=k;i++){
		dist[i] = 0;
		pq.push({0,i});
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(dist[now.sc] != now.fs)continue;
		for(auto nxt:paths[now.sc]){
			if(nxt.sc+dist[now.sc]<dist[nxt.fs]){
				dist[nxt.fs] = nxt.sc+dist[now.sc];
				pq.push({dist[nxt.fs],nxt.fs});
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(auto &nxt:paths[i]){
			assert(nxt.sc<inf&&nxt.sc>0);
			nxt.sc = dist[i]+dist[nxt.fs]+nxt.sc;
			assert(nxt.sc<inf&&nxt.sc>0);
			edges.push_back(make_tuple(nxt.sc,nxt.fs,i));
		}
	}
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		req[a].push_back(make_tuple(a,b,i));
		req[b].push_back(make_tuple(b,a,i));
	}
	fill(ans,ans+mxn,inf);
	sort(edges.begin(),edges.end());
	for(auto &i:edges){
		onion(get<1>(i),get<2>(i),get<0>(i));
	}
	for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';
	return 0;
}
