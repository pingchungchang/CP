#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 202;
ll dp[mxn][mxn][mxn];
vector<ll> v[3];
int a,b,c;

int dfs(int x,int y,int z){
	if(dp[x][y][z] != -1)return dp[x][y][z];
	dp[x][y][z] = 0;
	if(x&&y)dp[x][y][z] = max(dp[x][y][z],dfs(x-1,y-1,z)+v[0][x]*v[1][y]);
	if(y&&z)dp[x][y][z] = max(dp[x][y][z],dfs(x,y-1,z-1)+v[1][y]*v[2][z]);
	if(x&&z)dp[x][y][z] = max(dp[x][y][z],dfs(x-1,y,z-1)+v[0][x]*v[2][z]);
	return dp[x][y][z];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c;
	for(auto &i:v)i.push_back(0);
	for(int i = 0;i<a;i++){
		int k;
		cin>>k;
		v[0].push_back(k);
	}
	for(int i = 0;i<b;i++){
		int k;
		cin>>k;
		v[1].push_back(k);
	}
	for(int i = 0;i<c;i++){
		int k;
		cin>>k;
		v[2].push_back(k);
	}
	for(auto &i:v)sort(i.begin(),i.end());
	memset(dp,-1,sizeof(dp));
	cout<<dfs(a,b,c);
}
