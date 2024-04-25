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


struct edge{
	ll s,e,val;
	edge(){}
	edge(ll ss,ll ee,ll vv){
		s = ss,e = ee,val = vv;
	}
};
const int mxn = 2e5+10;
ll dist[mxn];
const ll inf = 1e18;
int main(){
	io
	fill(dist,dist+mxn,inf);
	ll n,m,k;
	cin>>n>>m>>k;
	edge paths[m];
	for(auto &i:paths){
		cin>>i.s>>i.e>>i.val;
	}
	dist[1] = 0;
	for(int i = 0;i<k;i++){
		ll p;
		cin>>p;
		p--;
		ll st = paths[p].s,ed = paths[p].e,v = paths[p].val;
		dist[ed] = min(dist[ed],dist[st]+v);
	}
	if(dist[n] >=inf)cout<<-1;
	else cout<<dist[n];
}

