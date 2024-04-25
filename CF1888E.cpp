#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int dist[mxn];
vector<pii> paths[mxn];
vector<int> route[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int k;
		cin>>k;
		while(k--){
			int a,b;
			cin>>a>>b;
			paths[a].push_back({b,i});
			paths[b].push_back({a,i});
		}
	}
	int C;
	cin>>C;
	for(int i = 1;i<=C;i++){
		int tmp;
		cin>>tmp;
		route[tmp].push_back(i);
	}
	fill(dist,dist+n+1,mxn<<1);
	dist[1] = 0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,1});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.fs != dist[now.sc])continue;
		for(auto nxt:paths[now.sc]){
			auto it = upper_bound(route[nxt.sc].begin(),route[nxt.sc].end(),now.fs);
			if(it == route[nxt.sc].end())continue;
			if(*it<dist[nxt.fs]){
				dist[nxt.fs] = *it;
				pq.push({*it,nxt.fs});
			}
		}
	}
	cout<<(dist[n]>mxn?-1:dist[n])<<'\n';
	return 0;
}
