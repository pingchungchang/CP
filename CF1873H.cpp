#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn];
int dist[mxn],head[mxn];
int deg[mxn];
int n,s,e;

void BFS(int st,int d[]){
	fill(d,d+n+1,-1);
	d[st] = 0;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt] == -1){
				dist[nxt] = dist[now]+1;
				q.push(nxt);
			}
		}
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++){
		head[i] = deg[i] = dist[i] = 0;
		paths[i].clear();
	}
	cin>>n>>s>>e;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
		deg[a]++;deg[b]++;
	}
	BFS(s,dist);
	queue<int> q;
	fill(dist,dist+n+1,1);
	for(int i = 1;i<=n;i++)if(deg[i] == 1)q.push(i);
	while(!q.empty()){
		auto now = q.front();
		dist[now] = 0;
		q.pop();
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(deg[nxt]==1)q.push(nxt);
		}
	}
	for(int i = 1;i<=n;i++)if(dist[i])dist[i] = 0,head[i] = i,q.push(i);else dist[i] = -1;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(dist[nxt] != -1)continue;
			dist[nxt] = dist[now]+1;
			head[nxt] = head[now];
			q.push(nxt);
		}
	}
	int h = head[e];
	BFS(h,dist);
	if(dist[s]<=dist[e])cout<<"NO\n";
	else cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
