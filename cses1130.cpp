#include <bits/stdc++.h>
using namespace std;

struct node{
	vector<int> path;
	int par;
	pair<int,int> dp;
	node(){
		dp = make_pair(-1,-1);
		par = -1;
	}
};
vector<node> treee;
void dfs(int now){
	for(int i = 0;i<treee[now].path.size();i++){
		if(treee[now].path[i] == treee[now].par)continue;
		int nxt = treee[now].path[i];
		treee[nxt].par = now;
		dfs(nxt);
	}
	return;
}
void rec(int now){
	treee[now].dp = make_pair(0,0);
	for(int i =0;i<treee[now].path.size();i++){
		int nxt = treee[now].path[i];
		if(nxt == treee[now].par)continue;
		rec(nxt);
		treee[now].dp.second += max(treee[nxt].dp.first,treee[nxt].dp.second);
	}
	for(int i = 0;i<treee[now].path.size();i++){
		int nxt = treee[now].path[i];
		if(nxt == treee[now].par)continue;
		treee[now].dp.first = max(treee[now].dp.first,treee[now].dp.second-max(treee[nxt].dp.first,treee[nxt].dp.second)+1+treee[nxt].dp.second);
	}
	return;
	
}
int main(){
	int n;
	cin>>n;
	treee = vector<node>(n,node());
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		treee[a].path.push_back(b);
		treee[b].path.push_back(a);
	}
	int root = 0;
	dfs(root);
	rec(root);
	cout<<max(treee[root].dp.first,treee[root].dp.second);
}
