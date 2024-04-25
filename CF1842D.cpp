#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll inf = 2e18;
const ll mxn = 110;
int n,m;
ll dist[mxn] = {};
vector<pll> paths[mxn];

void DIJKSTRA(int s){
	fill(dist,dist+n+1,inf);
	dist[s] = 0;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	pq.push({0,s});
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
	return;
}

int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
		paths[b].push_back({a,c});
	}
	DIJKSTRA(n);
	if(dist[1] > inf/2){
		cout<<"inf";
		return 0;
	}
	for(int i = 1;i<=n;i++)dist[i] = min(dist[i],dist[1]);
	bool flag = true;
	vector<pair<string,ll>> ans;
	cout<<dist[1]<<' ';
	while(flag){
		flag = false;
		for(int i = 1;i<=n;i++){
			if(dist[i])flag = true;
		}
		if(!flag)break;
		ll small = inf;
		for(int i = 1;i<=n;i++){
			if(dist[i])small = min(small,dist[i]);
		}
		string s(n,'0');
		for(int i = 1;i<=n;i++){
			if(dist[i]){
				s[i-1] = '1';
				dist[i] -= small;
			}
		}
		ans.push_back({s,small});
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
