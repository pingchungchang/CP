#include <bits/stdc++.h>
using namespace std;

vector<int> rooms;
vector<vector<int>> v;
void dfs(int i,int j,int &cnt){
	if(v[i][j] == 0)return;
	v[i][j] = 0;
	if(i%2 == 1&&j%2 == 1)cnt++;
	dfs(i,j+1,cnt);
	dfs(i+1,j,cnt);
	dfs(i,j-1,cnt);
	dfs(i-1,j,cnt);
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	v = vector<vector<int>>(n*2+1,vector<int>(m*2+1,0));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int k;
			cin>>k;
			v[2*i+1][2*j+1] = 1;
			if((k&1) ==0){
				v[2*i+1][2*j] = 1;
			}
			if((k&2) ==0){
				v[2*i+2][2*j+1] = 1;
			}
			if((k&4) == 0){
				v[2*i+1][2*j+2] = 1;
			}
			if((k&8) == 0){
				v[2*i][2*j+1] = 1;
			}
		}
	}
	for(int i = 1;i<=n*2;i++){
		for(int j = 1;j<=m*2;j++){
			if(v[i][j] != 0){
				int cnt = 0;
				dfs(i,j,cnt);
				if(cnt != 0)rooms.push_back(cnt);
			}
		}
	}
	sort(rooms.begin(),rooms.end());
	for(int i =rooms.size()-1;i>=0;i--)cout<<rooms[i]<<' ';
	return 0;
}
//NESW
