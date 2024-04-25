#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> paths(1e5+5);
vector<int> dist(1e5+5,-1);
vector<int> goneto(1e5+5,-1);
int n,m;
void dfs(int now){
	if(now == n-1)return;
	int ans = -2;
	for(int i =0;i<paths[now].size();i++){
		int nxt = paths[now][i];
		if(dist[nxt] == -1)dfs(nxt);
		if(dist[nxt]+1>ans&&dist[nxt]+1>0){
			ans = dist[nxt]+1;
			goneto[now] = nxt;
		}
	}
	dist[now] = ans;
	return;
}
int main(){
	cin>>n>>m;
	dist[n-1] =0;
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b);
	}
	dfs(0);
	if(dist[0] == -2){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	cout<<dist[0]+1<<'\n';
	int k =0;
	while(k != n-1){
		cout<<k+1<<' ';
		k = goneto[k];
	}
	cout<<n;
}
