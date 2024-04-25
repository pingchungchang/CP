/*
what is the minimum price of such a route?
how many minimum-price routes are there? (modulo 109+7)
what is the minimum number of flights in a minimum-price route?
what is the maximum number of flights in a minimum-price route?
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;	
vector<vector<pair<ll,ll>>> paths(1e5+5);
vector<ll> dist(1e5+5,1e17+5);
vector<ll> maxv(1e5+5,0);
vector<ll> minv(1e5+5,1e5+6);
vector<ll> times(1e5+5,0);
ll n,m;
//be aware of the modulos
int main(){
	cin>>n>>m;
	for(ll i =0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a-1].push_back(make_pair(b-1,c));
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push(make_pair(0,0));
	times[0] =1;
	dist[0] = 0;
	maxv[0] = 0;
	minv[0] = 0;
	while(!pq.empty()){
		ll now = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if(val>dist[now])continue;
		for(ll i =0;i<paths[now].size();i++){
			ll nxt = paths[now][i].first;
			if(dist[nxt] == paths[now][i].second+val){
				times[nxt] += times[now];
				times[nxt]%=mod;
				maxv[nxt] = max(maxv[nxt],maxv[now]+1);
				minv[nxt] = min(minv[nxt],minv[now]+1);
				continue;
			}
			else if(dist[nxt]>paths[now][i].second+val){
				pq.push(make_pair(paths[now][i].second+val,nxt));
				times[nxt] = times[now];
				maxv[nxt] = maxv[now]+1;
				minv[nxt] = minv[now]+1;
				dist[nxt] = paths[now][i].second+val;
				continue;
			}
		}
	}
	cout<<dist[n-1]<<' '<<times[n-1]%mod<<' '<<minv[n-1]<<' '<<maxv[n-1];
}
