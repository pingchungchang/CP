#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> paths(1e5+5);
vector<int> val(1e5+5,0);
int n,m;
vector<int> ans;
void dfs(int now){
	val[now] = -1;
	for(int i =0;i<paths[now].size();i++){
		int nxt = paths[now][i];
		val[nxt]--;
		if(val[nxt] == 0){
			ans.push_back(nxt);
			dfs(nxt);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b);
		val[b]++;
	}
	for(int i =0;i<n;i++){
		if(val[i] == 0){
			ans.push_back(i);
			dfs(i);
		}
	}
	if(ans.size()!=n){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	for(int i =0;i<ans.size();i++){
		cout<<ans[i]+1<<' ';
	}
}
