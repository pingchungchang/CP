#include <bits/stdc++.h>
using namespace std;

int v[550][550] = {};
vector<pair<int,int>> dir = {make_pair(0,1),make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(1,1),make_pair(-1,1),make_pair(1,-1),make_pair(-1,-1)};
void dfs(int i,int j){
	v[i][j] = 0;
	for(auto p:dir){
		if(v[i+p.first][j+p.second])dfs(i+p.first,j+p.second);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			char c;
			cin>>c;
			v[i][j] = c-'0';
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(v[i][j] == 1){
				dfs(i,j);
				ans++;
			}
		}
	}
	vector<int> lev = {1,2,4,6,10,12,14,16,18,20};
	int pos = lower_bound(lev.begin(),lev.end(),ans)-lev.begin();
	if(pos>=10)cout<<10;
	else if(ans != 0) cout<<pos+1;
	else cout<<0;
}
