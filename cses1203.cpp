#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
const ll inf = 1e18;
vector<pii> g[mxn],rg[mxn];
ll d1[mxn],d2[mxn];
vector<int> ans;
int n,m;
vector<int> groups[mxn],dag[mxn],st;
int gid = 0,cnt = 0;
int idx[mxn],low[mxn];


void DIJKSTRA(int s,ll dist[],vector<pii> paths[]){
	fill(dist,dist+mxn,inf);
	dist[s] = 0;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(dist[now.sc] != now.fs)continue;
		for(auto nxt:paths[now.sc]){
			if(dist[nxt.fs]>dist[now.sc]+nxt.sc){
				dist[nxt.fs] = dist[now.sc]+nxt.sc;
				pq.push(make_pair(dist[nxt.fs],nxt.fs));
			}
		}
	}
	return;
}

void tarjan(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:dag[now]){
		if(!idx[nxt]){
			tarjan(nxt);
			if(low[nxt] == idx[now]){
				gid++;
				while(st.back() != nxt){
					groups[st.back()].push_back(gid);
					st.pop_back();
				}
				groups[st.back()].push_back(gid);
				st.pop_back();
				groups[now].push_back(gid);
			}
			low[now] = min(low[now],low[nxt]);
		}
		else low[now] = min(low[now],idx[nxt]);
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		rg[b].push_back({a,c});
	}
	DIJKSTRA(1,d1,g);
	DIJKSTRA(n,d2,rg);
	for(int i = 1;i<=n;i++){
		if(d1[i]+d2[i] == d2[1]){
			int now = i;
			for(auto nxt:g[now]){
				if(d1[nxt.fs]+d2[nxt.fs] == d2[1]&&d1[nxt.fs] == nxt.sc+d1[now]){
					dag[now].push_back(nxt.fs);
					dag[nxt.fs].push_back(now);
				}
			}
		}
	}
	tarjan(1);
	for(int i = 1;i<=n;i++){
		if(groups[i].size()>1||i == 1||i == n){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';
}
