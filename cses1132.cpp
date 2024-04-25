#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> paths;
int dist[200005];
int bfs(int root){
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	q.push(root);
	dist[root] = 0;
	pair<int,int> biggest = make_pair(0,root);
	while(!q.empty()){
		int now =q.front();
		q.pop();
		for(int nxt:paths[now]){
			if(dist[nxt] == -1){
				q.push(nxt);
				dist[nxt] = dist[now]+1;
				biggest = max(biggest,make_pair(dist[nxt],nxt));
			}
		}
	}
	return biggest.second;
}
int main(){
	cin>>n;
	paths = vector<vector<int>>(n);
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	int k = bfs(0);
	int j = bfs(k);
	int v[200005] = {};
	for(int i = 0;i<n;i++)v[i] = dist[i];
	bfs(j);
	for(int i = 0;i<n;i++)cout<<max(v[i],dist[i])<<' ';
}
