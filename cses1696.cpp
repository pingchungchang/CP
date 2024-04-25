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

const int mxn = 505;
bool paths[mxn][mxn],visy[mxn];
int matchx[mxn],matchy[mxn];
int n,m;
bool dfs(int now){
	for(int i = 1;i<=m;i++){
		if(paths[now][i]&&!visy[i]){
			visy[i] = true;
			if(matchy[i] == 0){
				matchy[i] = now;
				matchx[now] = i;
				return true;
			}
			else if(dfs(matchy[i])){
				matchy[i] = now;
				matchx[now] = i;
				return true;
			}
		}
	}
	return false;
}
int main(){
	io
	int k;
	cin>>n>>m>>k;
	for(int i = 0;i<k;i++){
		int a,b;
		cin>>a>>b;
		paths[a][b] = true;
	}
	int ans = 0;
	for(int i= 1;i<=n;i++){
		memset(visy,false,sizeof(visy));
		if(dfs(i))ans++;
	}
	cout<<ans<<'\n';
	for(int i = 1;i<=n;i++){
		if(matchx[i])cout<<i<<' '<<matchx[i]<<'\n';
	}
}

