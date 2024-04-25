#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
	vector<int> goneto(100005,-1);
vector<vector<int>> paths(100005);
void getall(int now){
	for(int i =0;i<paths[now].size();i++){
		int nxt = paths[now][i];
		if(goneto[nxt] == 0){
			ans.push_back(nxt);
			goneto[nxt] = 1;
			getall(nxt);
			return;
		}
	}
	return;
}
bool dfs(int now){
	bool returns = false;
	for(int i =0;i<paths[now].size();i++){
		int nxt = paths[now][i];
		if(goneto[nxt] == 0){
			goneto[nxt] = 1;
			ans.push_back(nxt);
			getall(nxt);
			return true;
		}
		else if(goneto[nxt] == -2)continue;
		goneto[nxt] = 0;
		returns = returns|dfs(nxt);
		if(returns == true)return true;
	}
	goneto[now] = -2;
	return returns;
}
int main(){
	int n,m;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a-1].push_back(b-1);
	}
	for(int i =0;i<n;i++){
		if(goneto[i] == -1){
			goneto[i] = 0;
			dfs(i);
		}
		if(ans.size()!=0){
			cout<<ans.size()+1<<'\n';
			for(int j =0;j<ans.size();j++){
				cout<<ans[j]+1<<' ';
			}
			cout<<ans[0]+1;
			return 0;
		}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}
