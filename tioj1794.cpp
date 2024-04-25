#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3030;
int arr[mxn][mxn];
pii dir[] = {{1,0},{0,1},{-1,0},{0,-1}};

int dfs(int r,int c,int id){
	arr[r][c] = -1;
	int re = 1;
	for(auto &i:dir){
		pii nxt = {r+i.fs,c+i.sc};
		if(arr[nxt.fs][nxt.sc] == id)re += dfs(nxt.fs,nxt.sc,id);
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	memset(arr,-1,sizeof(arr));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(arr[i][j] != -1)ans = max(ans,dfs(i,j,arr[i][j]));
		}
	}
	cout<<ans;
}
