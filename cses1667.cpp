#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> road(n);
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	vector<int> goneto(n,-1);
	queue<int> q;
	goneto[0] = 0;
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(now == n-1){
			vector<int> path;
			int j = now;
			while(j !=0){
				path.push_back(j);
				j = goneto[j];
			}
			cout<<path.size()+1<<'\n';
			cout<<'1'<<' ';
			for(int i = path.size()-1;i>=0;i--){
				cout<<path[i]+1<<' ';
			}
			return 0;
		}
		for(int i =0;i<road[now].size();i++){
			int nxt = road[now][i];
			if(goneto[nxt] == -1){
				goneto[nxt] = now;
				q.push(nxt);
			}
		}
	}
	cout<<"IMPOSSIBLE";
}
