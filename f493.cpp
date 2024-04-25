#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> v;

int dfs(int r,int c){
	v[r][c] = '#';
	int returns = 1;
	if(v[r+1][c] == 'W')returns += dfs(r+1,c);
	if(v[r][c+1] == 'W')returns += dfs(r,c+1);
	if(v[r][c-1] == 'W')returns += dfs(r,c-1);
	if(v[r-1][c] == 'W')returns += dfs(r-1,c);
	return returns;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	v = vector<vector<char>>(n+2,vector<char>(m+2,'#'));
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>v[i][j];
	int big = 0;
	int num = 0;
	int small = INT_MAX;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(v[i][j] == 'W'){
				int x = dfs(i,j);
				num++;
				big = max(x,big);
				small = min(x,small);
			}
		}
	}
	if(num == 0){
		small = 0;
	}
	cout<<big<<' '<<small<<' '<<num;
}
