#include <bits/stdc++.h>
using namespace std;

constexpr int mx = 1505;
int n,m;
vector<vector<int>> v;
vector<vector<bool>> goneto;
vector<pair<int,int>> ans;

void dfs(int x,int y){
	ans.push_back(make_pair(x,y));
	goneto[x][y] = true;
	if(goneto[x+1][y] == false&&v[x+1][y]>=v[x][y])dfs(x+1,y);
	if(goneto[x-1][y] == false&&v[x-1][y]>=v[x][y])dfs(x-1,y);
	if(goneto[x][y+1] == false&&v[x][y+1]>=v[x][y])dfs(x,y+1);
	if(goneto[x][y-1] == false&&v[x][y-1]>=v[x][y])dfs(x,y-1);
}
int main(){
	cin>>n>>m;
	goneto = vector<vector<bool>>(n+2,vector<bool>(2+m,true));
	v = vector<vector<int>>(n+2,vector<int>(m+2,-1000000));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin>>v[i][j];
			goneto[i][j] = false;
		}
	}
	int x,y;
	cin>>x>>y;
	x++,y++;
	dfs(x,y);
	sort(ans.begin(),ans.end());
	for(int i = 0;i<ans.size();i++){
		printf("(%d,%d)\n",ans[i].first-1,ans[i].second-1);
	}
	return 0;
}
