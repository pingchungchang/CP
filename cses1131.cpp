#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> paths;

int goneto[200005] = {};
int n;
int bfs(int root){
	memset(goneto,-1,sizeof(goneto));
	queue<int> q;
	q.push(root);
	goneto[root] = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i:paths[now]){
			if(goneto[i] == -1){
				goneto[i] = goneto[now]+1;
				q.push(i);
			}
		}
	}
	int returns = 0;
	int val = 0;
	for(int i = 0;i<n;i++){
		if(goneto[i]>val){
			returns = i;
			val = goneto[i];
		}
	}
	return returns;
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
	cout<<goneto[j];
}
