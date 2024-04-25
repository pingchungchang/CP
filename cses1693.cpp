#include <bits/stdc++.h>
using namespace std;

vector<set<int>> paths(1e5+5);
vector<int> ans;
vector<int> in(1e5+5,0);
void dfs(int now){
	while(paths[now].size()!= 0){
		int nxt = *paths[now].begin();
		paths[now].erase(nxt);
//		paths[nxt].erase(paths[nxt].find(now));
		dfs(nxt);
	}
	ans.push_back(now);
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].insert(b);
		in[b]++;
	}
	in[1]++;
	in[n]--;
	for(int i = 1;i<=n;i++){
		if(in[i]!= paths[i].size()){
//			cout<<in[i]<<paths[i].size();
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
