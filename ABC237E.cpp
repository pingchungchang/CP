#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,m;
	cin>>n>>m;
	vector<ll> dist(n,LONG_LONG_MAX);
	vector<vector<pair<ll,ll>>> paths(n);
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a-1].push_back(make_pair(b-1,max((ll)0,v[b-1]-v[a-1])));
		paths[b-1].push_back(make_pair(a-1,max((ll)0,v[a-1]-v[b-1])));
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push(make_pair(0,0));
	dist[0] = 0;
	while(!pq.empty()){
		ll now = pq.top().second;
		ll val = pq.top().first;
		pq.pop();
		if(val>dist[now])continue;
		for(pair<ll,ll> nxt:paths[now]){
			if(dist[nxt.first]>nxt.second+val){
				dist[nxt.first] = nxt.second+val;
				pq.push(make_pair(nxt.second+val,nxt.first));
			}
		}
	}
	ll ans = 0;
	for(ll i = 0;i<dist.size();i++){
		ans = max(ans,v[0]-v[i]-dist[i]);
	}
	cout<<ans;
}
