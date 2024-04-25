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
#define int ll
const ll mxn = 1e5+10;
vector<pll> paths[mxn],rpaths[mxn];
ll dist[mxn],rdist[mxn],val[mxn];
bitset<mxn> goneto;
void dijkstra(vector<pll> g[],ll d[]){
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	fill(d,d+mxn,(ll)INT_MAX);
	d[1] = 0;
	goneto.reset();
	pq.push({0,1});
	while(!pq.empty()){
		auto now = pq.top();
//		cout<<now.fs<<':'<<now.sc<<endl;
		pq.pop();
		swap(now.fs,now.sc);
		if(goneto[now.fs])continue;
		goneto[now.fs] = true;
		for(auto nxt:g[now.fs]){
			if(d[nxt.fs]>now.sc+nxt.sc){
				d[nxt.fs] = now.sc+nxt.sc;
				pq.push({now.sc+nxt.sc,nxt.fs});
			}
		}
	}
	return;
}
main(){
	io
	int n,m,t;
	cin>>n>>m>>t;
	for(int i = 1;i<=n;i++)cin>>val[i];
	for(int i= 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
		rpaths[b].push_back({a,c});
	}
	dijkstra(paths,dist);
	dijkstra(rpaths,rdist);
	ll ans = 0;
//	for(int i = 1;i<=n;i++)cout<<dist[i]<<',';cout<<endl;
//	for(int i = 1;i<=n;i++)cout<<rdist[i]<<',';cout<<endl;
	for(int i = 1;i<=n;i++){
		if(t>dist[i]+rdist[i]){
			ans = max(ans,val[i]*(t-dist[i]-rdist[i]));
		}
//		cout<<i<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
}

