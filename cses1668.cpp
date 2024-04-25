#include <bits/stdc++.h>
using namespace std;


vector<int> teams(200001,-1);
vector<vector<int>> v(200001);
bool dfs(int k,int num){
	num = 3-num;
	bool done = true;
	for(int i =0;i<v[k].size();i++){
		int nxt = v[k][i];
		if(teams[nxt]==-1){
			teams[nxt] = num;
			done = done&dfs(nxt,num);
		}
		else if(teams[nxt] != num){
			return false;
		}
	}
	return done;
}
int main(){
	int n,m;
	cin>>n>>m;

	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i =0;i<n;i++){
		if(teams[i] == -1){
			teams[i] = 1;
			bool errors = dfs(i,1);
			if(errors== false){
				cout<<"IMPOSSIBLE";
				return 0;
			}
		}
	}
	for(int i =0;i<n;i++){
		cout<<teams[i]<<' ';
	}
}
