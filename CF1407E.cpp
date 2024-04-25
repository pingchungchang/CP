#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5e5+10;

int n,m;
int dist[mxn][2];
vector<pii> paths[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[b].push_back({a,c});
	}

	memset(dist,-1,sizeof(dist));
	dist[n][0] = dist[n][1] = 0;
	queue<pii> q;
	q.push({n,0});q.push({n,1});

	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now.fs]){
			if(dist[nxt.fs][nxt.sc] != -1)continue;
			dist[nxt.fs][nxt.sc] = dist[now.fs][now.sc]+1;
			if(dist[nxt.fs][nxt.sc^1] != -1)q.push(nxt);
		}
	}
	for(auto &i:dist)for(auto &j:i)if(j == -1)j = 1e9;
	cout<<(max(dist[1][0],dist[1][1])>=n?-1:max(dist[1][0],dist[1][1]))<<'\n';
	//for(int i = 1;i<=n;i++)cout<<dist[i][0]<<' ';cout<<'\n';for(int i= 1;i<=n;i++)cout<<dist[i][1]<<' ';cout<<'\n';
	for(int i = 1;i<=n;i++){
		if(dist[i][0]>dist[i][1])cout<<0;
		else cout<<1;
	}
	return 0;
}
