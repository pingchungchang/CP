#include <bits/stdc++.h>
using namespace std;

vector<string> v(1000);
int n,m;
void dfs(int i,int j){
	v[i][j] = '#';
	if(i+1<n&&v[i+1][j] == '.')dfs(i+1,j);
	if(i-1>=0&&v[i-1][j] == '.')dfs(i-1,j);
	if(j+1<m&&v[i][j+1] == '.')dfs(i,j+1);
	if(j-1>=0&&v[i][j-1]=='.')dfs(i,j-1);
	return;
}
int main(){
	cin>>n>>m;
	for(int i =0;i<n;i++){
		cin>>v[i];
	}
	int ans =0;
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(v[i][j] == '.'){
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans;
}
