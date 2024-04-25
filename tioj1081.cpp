#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const int mxn = 1010;
bool arr[mxn][mxn];
int ans = 0;
pii dir[] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
void dfs(int r,int c){
	arr[r][c] = 0;
	for(auto nxt:dir){
		if(arr[r+nxt.fs][c+nxt.sc])dfs(r+nxt.fs,c+nxt.sc);
	}
	return;
}
int n,m;
void solve(){
	ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=m;j++){
			char c;
			cin>>c;
			if(c == '1')arr[i][j] = true;
//			cin>>arr[i][j];
		}
	}
	for(int i = 1;i<=n;i++)for(int j= 1;j<=m;j++)if(arr[i][j]){
		dfs(i,j);
		ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	while(cin>>n>>m){
		if(!n&&!m)return 0;
		solve();
	}
}
