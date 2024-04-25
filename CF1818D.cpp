#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2020;
vector<int> paths[mxn];
int dist[mxn][mxn],pre[mxn][mxn];
int fa[mxn];

void BFS(int s,int d[],int p[]){
	queue<int> q;
	q.push(s);
	d[s] = 0;
	p[s] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(d[nxt]>d[now]+1){
				d[nxt] = d[now]+1;
				p[nxt] = now;
				q.push(nxt);
			}
		}
	}
	return;
}

void solve(){
	int n,m;
	cin>>n>>m;
	fill(dist,dist+n+1,mxn);
	fill(pre,pre+n+1,0);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
