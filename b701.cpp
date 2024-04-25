#include <bits/stdc++.h>
using namespace std;

int cal = 0;
int nor,wes,eas,sou;
vector<vector<int>> v;
void dfs(int x,int y){
	if(x>v.size()-1||x<0||y>v[0].size()-1||y<0||v[x][y] == 0)return;
	v[x][y] = 0;
	cal++;
	nor = min(x,nor);
	sou = max(x,sou);
	eas = max(eas,y);
	wes = min(y,wes);

	dfs(x,y-1);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x+1,y);
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	v = vector<vector<int>>(n,vector<int>(m,0));
	nor = INT_MAX,sou = 0,eas = 0,wes = INT_MAX;
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			int k;
			cin>>k;
			v[i][j] = k;
		}
	}
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(v[i][j] == 1){
			nor = INT_MAX,sou = 0,eas = 0,wes = INT_MAX,cal=0;
			dfs(i,j);
			cout<<wes<<' '<<nor<<' '<<eas<<' '<<sou<<' '<<cal<<'\n';
				
			}
		}
	}
}
