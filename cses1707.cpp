#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2505;
vector<pii> paths[mxn];
pii edges[mxn*2];
int dist[mxn];

void BFS(int s,int no){
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(nxt.sc == no)continue;
			if(dist[nxt.fs] == -1){
				dist[nxt.fs] = dist[now]+1;
				q.push(nxt.fs);
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		cin>>edges[i].fs>>edges[i].sc;
		paths[edges[i].fs].push_back({edges[i].sc,i});
		paths[edges[i].sc].push_back({edges[i].fs,i});
	}
	int ans = mxn;
	for(int i = 1;i<=m;i++){
		BFS(edges[i].fs,i);
		if(dist[edges[i].sc] != -1)ans = min(ans,dist[edges[i].sc]+1);
	}
	cout<<(ans == mxn?-1:ans);
}
