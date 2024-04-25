#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<ll> dist(n,LONG_LONG_MAX);
	dist[0] =0;
	vector<vector<pair<ll,ll>>> paths(n);
	for(int i =0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		paths[a].push_back(make_pair(b,c));
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push(make_pair(0,0));
	vector<bool> goneto(n,false);
	while(!pq.empty()){
		pair<ll,ll> now = pq.top();
		pq.pop();
		if(goneto[now.second] == true)continue;
		goneto[now.second] = true;
		for(int i =0;i<paths[now.second].size();i++){
			ll nxt = paths[now.second][i].first;
			if(dist[nxt]>paths[now.second][i].second+dist[now.second]){
				dist[nxt] = paths[now.second][i].second+now.first;
				pq.push(make_pair(dist[nxt],nxt));
			}
		}
	}
	for(int i =0;i<n;i++)cout<<dist[i]<<' ';
}
