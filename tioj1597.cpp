#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt")

struct Edge{
	ll a,b,to;
	Edge(ll ta,ll tb,ll tt){
		a = ta,b = tb,to = tt;
	}
	Edge(){}
	ll operator()(int k){
		return a*k+b;
	}
};

const ll inf = 4e18;
const int mxn = 4e4+10;
vector<Edge> paths[mxn];
ll dist[mxn];
int n,m,a,b,d;
unordered_map<int,ll> mp;

	priority_queue<pll,vector<pll>,greater<pll>> pq;
	inline ll DIJKSTRA(int s,int e,int dt){
		while(!pq.empty())pq.pop();
		fill(dist,dist+n+1,inf);
		dist[s] = 0;
		pq.push(make_pair(0,s));
		while(!pq.empty()){
			auto now = pq.top();
			pq.pop();
			if(now.sc == e)return now.fs;
			if(now.fs != dist[now.sc])continue;
			for(auto nxt:paths[now.sc]){
				assert(nxt(dt)>=0);
				if(dist[nxt.to]>dist[now.sc]+nxt(dt)){
					dist[nxt.to] = dist[now.sc]+nxt(dt);
					pq.push(make_pair(dist[nxt.to],nxt.to));
				}
			}
		}
		return dist[e];
	}
	inline ll f(int dt){
		if(mp.find(dt) != mp.end())return mp[dt];
		ll re = 0;
		re += DIJKSTRA(a,b,dt);
		re += DIJKSTRA(b,a,dt);
		return mp[dt] = re;
	}
	inline void getans(){
		int l = 0,r = d-1;
		while(l+1<r){
			ll mid = (l+r)>>1;
			ll ta = f(mid),tb = f(mid+1);
			if(ta == tb){
				l = mid;
				break;
			}
			if(f(mid)>f(mid+1))r = mid;
			else l = mid+1;
		}
		ll sm = f(l);
		if(l+1<d)sm = max(sm,f(l+1));
		cout<<sm-min(f(0),f(d-1));
	}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>a>>b>>d;
	for(int i = 0;i<m;i++){
		ll ta,tb,tc,td,te,tf;
		cin>>ta>>tb>>tc>>td>>te>>tf;
		paths[ta].push_back(Edge(td,tc,tb));
		paths[tb].push_back(Edge(tf,te,ta));
	}
	getans();
	return 0;
}
