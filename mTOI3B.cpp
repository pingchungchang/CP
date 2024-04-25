#include <bits/stdc++.h>
using namespace std;

struct node{
	vector<int> v;
	node(int k){
		v = vector<int>(k+1,INT_MAX);
	}
};
vector<vector<int>> paths;
vector<vector<int>> cap;
vector<node> dp;
void dfs(int now,int val){
	
}
int main(){
	int n;
	cin>>n;
	paths = vector<vector<int>>(n);
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	int c;
	cin>>c;
	dp = vector<node>(k,node(c));
	cap = vector<vector<int>>(n,vector<int>(c+1,0));
	for(int i = 0;i<n;i++)for(int j = 1;j<=c;j++)cin>>cap[i][j];
	int k;
	cin>>k;
	dfs(0,k);
}
