#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 2020;
const ll inf = 1e18;
ll n,m,w;
ll arr[mxn][mxn];
ll d1[mxn][mxn],d2[mxn][mxn];
pii dir[] = {{-1,0},{1,0},{0,1},{0,-1}};

void BFS(int sx,int sy,ll dist[mxn][mxn]){
	queue<pii> q;
	for(int i = 0;i<mxn;i++)for(int j = 0;j<mxn;j++)dist[i][j] = inf;
	dist[sx][sy] = 0;
	q.push({sx,sy});
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto &tmp:dir){
			pii nxt = {now.fs+tmp.fs,now.sc+tmp.sc};
			if(arr[nxt.fs][nxt.sc] == -1)continue;
			if(dist[nxt.fs][nxt.sc] == inf)dist[nxt.fs][nxt.sc] = dist[now.fs][now.sc]+w,q.push(nxt);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>w;
	memset(arr,-1,sizeof(arr));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	BFS(1,1,d1);
	BFS(n,m,d2);
	ll ans = d1[n][m];
	pll small = {inf,inf};
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(arr[i][j]<=0)continue;
			small.fs = min(small.fs,d1[i][j]+arr[i][j]);
			small.sc = min(small.sc,d2[i][j]+arr[i][j]);
		}
	}
	ans = min(ans,small.fs+small.sc);
	cout<<(ans>=inf?-1:ans);
}
