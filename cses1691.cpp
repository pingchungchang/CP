#include <bits/stdc++.h>
using namespace std;

vector<set<int>> paths(1e5+5);
vector<int> ans;

void dfs(int now){
	while(paths[now].size()!=0){
		int nxt = *paths[now].begin();
		paths[now].erase(nxt);
		paths[nxt].erase(now);
		dfs(nxt);
	}
	ans.push_back(now);
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].insert(b);
		paths[b].insert(a);
	}
	for(int i = 1;i<=n;i++){
		if(paths[i].size()&1 == 1){
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	dfs(1);
	if(ans.size()!= m+1){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	for(int i = ans.size()-1;i>=0;i--){
		cout<<ans[i]<<' ';
	}
}
