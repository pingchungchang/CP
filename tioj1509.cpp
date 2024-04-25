#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 1e6+1;
vector<vector<pair<int,ll>>> paths;
vector<vector<pair<int,ll>>> p2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	paths = vector<vector<pair<int,ll>>>(n+1);
	p2 = vector<vector<pair<int,ll>>>(n+1);
	for(int i = 0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		paths[a].push_back(make_pair(b,c));
		p2[b].push_back(make_pair(a,c));
	}
	vector<ll> dist(n+1,LONG_LONG_MAX);
	priority_queue<pair<int,ll>,vector<pair<int,ll>>,greater<pair<int,ll>>> pq;
	pq.push(make_pair(1,0));
	dist[1] = 0;
	while(!pq.empty()){
		int now = pq.top().first;
		ll val = pq.top().second;
		pq.pop();
		for(int i = 0;i<paths[now].size();i++){
			int nxt = paths[now][i].first;
			if(dist[nxt]>val+paths[now][i].second){
				dist[nxt] = paths[now][i].second+val;
				pq.push(make_pair(nxt,dist[nxt]));
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(dist[i] == LONG_LONG_MAX){
			cout<<"0";
			return 0;
		}
		ans += dist[i];
	}
	dist = vector<ll>(mx,LONG_LONG_MAX);
	pq.push(make_pair(1,0));
	dist[1] = 0;
	while(!pq.empty()){
		int now = pq.top().first;
		ll val = pq.top().second;
		pq.pop();
		for(int i = 0;i<p2[now].size();i++){
			int nxt = p2[now][i].first;
			if(dist[nxt]>p2[now][i].second+dist[now]){
				dist[nxt] = dist[now]+p2[now][i].second;
				pq.push(make_pair(nxt,dist[nxt]));
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(dist[i] == LONG_LONG_MAX){
			cout<<"0";
			return 0;
		}
		ans += dist[i];
	}
	cout<<ans;
}
