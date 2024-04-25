#include <bits/stdc++.h>
using namespace std;

int p1 = -1,p2 = -1;
void dfs(int now,vector<vector<int>> &paths,vector<int>&parent){
	for(int i =0;i<paths[now].size();i++){
		if(p1 != -1)return;
		int nxt = paths[now][i];
		if(nxt == parent[now])continue;
		if(parent[nxt] != -1){
			p1 = nxt;
			p2 = now;
			return;
		}
		else{
			parent[nxt] = now;
			dfs(nxt,paths,parent);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> paths(n);
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	vector<int> parent(n,-1);
	for(int i =0;i<n;i++){
		if(parent[i] == -1){
			parent[i] = i;
			dfs(i,paths,parent);
			if(p1 != -1){
				break;
			}
		}
	}
	if(p1 == -1){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	deque<int> s1;
	deque<int> s2;
	s1.push_back(p1);
	s2.push_back(p2);
	while(parent[s1.back()] != s1.back()){
		s1.push_back(parent[s1.back()]);
	}
	while(parent[s2.back()] != s2.back()){
		s2.push_back(parent[s2.back()]);
	}
	int k;
	while(!s1.empty()&&!s2.empty()&&s1.back()==s2.back()){
		k = s1.back();
		s1.pop_back();
		s2.pop_back();
	}
	cout<<2+s1.size()+s2.size()<<'\n';

	cout<<k+1<<' ';
	while(!s2.empty()){
		cout<<1+s2.back()<<' ';
		s2.pop_back();
	}
	while(!s1.empty()){
		cout<<s1.front()+1<<' ';
		s1.pop_front();
	}
	cout<<k+1;
}
