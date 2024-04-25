#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1010;
int arr[mxn][mxn];
pair<int,int> dir[] = {{0,1},{0,-1},{1,0},{-1,0}};

int dfs(int r,int c){
	int re = arr[r][c];
	arr[r][c] = 0;
	for(auto nxt:dir){
		int nr = r+nxt.fs,nc = c+nxt.sc;
		if(arr[nr][nc])re += dfs(nr,nc);
	}
	return re;
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)cin>>arr[i][j];
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(arr[i][j])ans = max(ans,dfs(i,j));
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
