#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> v;
int dices;
int pts;;
void dfs(int i,int j,int col,int x){
	if(i<0||i>=n||j>=m||j<0)return;
	if(v[i][j]!= col)return;
	v[i][j] = x;
	dfs(i+1,j,col,x);
	dfs(i,j+1,col,x);
	dfs(i-1,j,col,x);
	dfs(i,j-1,col,x);
	dfs(i-1,j-1,col,x);
	dfs(i-1,j+1,col,x);
	dfs(i+1,j-1,col,x);
	dfs(i+1,j+1,col,x);
	return;
}
void solve(){
	dices= 0;
	pts = 0;
	v = vector<vector<int>>(n,vector<int>(m));
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			char c;
			cin>>c;
			v[i][j] = c-'0';
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(v[i][j] == 2){
				pts++;
				dfs(i,j,v[i][j],1);
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(v[i][j] == 1){
				dices++;
				dfs(i,j,v[i][j],0);
			}
		}
	}
	cout<<dices<<' '<<pts<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n>>m){
		solve();
	}
}
