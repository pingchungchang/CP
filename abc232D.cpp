#include <bits/stdc++.h>
using namespace std;

int v[105][105] = {};
char graph[105][105];
int main(){
	int n,m;
	cin>>n>>m;
	int ans = 0;
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>graph[i][j];
	for(int i = 1;i<=n;i++){
		if(graph[i][1] != '.'){
			break;
		}
		v[i][1] = v[i-1][1]+1;
		ans = max(ans,v[i][1]);
	}
	for(int i = 1;i<=m;i++){
		if(graph[1][i] != '.'){
			break;
		}
		v[1][i] = v[1][i-1]+1;
		ans = max(ans,v[1][i]);
	}
	for(int i = 2;i<=n;i++){
		for(int j = 2;j<=m;j++){
			if(graph[i][j] == '#')continue;
			if(graph[i][j-1] == '.'&&v[i][j-1]!= 0){
				v[i][j] = max(v[i][j],v[i][j-1]+1);
			}
			if(graph[i-1][j] == '.'&&v[i-1][j]!= 0){
				v[i][j] = max(v[i][j],v[i-1][j]+1);
			}
			ans = max(ans,v[i][j]);
		}
	}
	cout<<ans;
}
