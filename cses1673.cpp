#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<int,ll>>> paths;
vector<ll> goneto(2505,LONG_LONG_MIN);
int n;
bool bf(){
	bool returns = false;
	for(int i =0;i<n;i++){
		if(goneto[i] == LONG_LONG_MIN)continue;
		for(int j = 0;j<paths[i].size();j++){
			int nxt = paths[i][j].first;
			if(goneto[nxt] < paths[i][j].second+goneto[i]){
				goneto[nxt] = paths[i][j].second+goneto[i];
				returns = true;
			}
		}
	}
	return returns;
}
void dfs(int now){
	goneto[now] =1;
	for(int i = 0;i<paths[now].size();i++){
		int nxt = paths[now][i].first;
		if(goneto[nxt] == 0)dfs(nxt);
	}
	return;
}
void cycles(){
	vector<ll> g1 = goneto;
	for(int i = 0;i<n;i++){
		bf();
	}
	vector<int> v;
	for(int i = 0;i<n;i++){
		if(goneto[i]!=g1[i])v.push_back(i);
	}
	for(int i =0;i<n;i++)goneto[i] = 0;
	for(int i = 0;i<v.size();i++){
		if(goneto[v[i]] == 0)dfs(v[i]);
	}
	if(goneto[n-1] == 0){
		cout<<g1[n-1];
	}
	else cout<<-1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin>>n>>m;
	paths = vector<vector<pair<int,ll>>>(n);
	for(int i =0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		paths[a].push_back(make_pair(b,(ll)c));
	}
	goneto[0] = 0;
	for(int i = 0;i<n;i++){
		bf();
	}
	if(bf() == true){
		cycles();
		return 0;
	}
	else{
		ll ans = INT_MIN;
		cout<<goneto[n-1];
	}
}
