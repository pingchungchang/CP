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

const int mxn = 10;
ll paths[mxn][mxn];
ll n,k;
ll ans;
void dfs(int now,int mask,ll dist){
	if(mask == (1<<n)-1){
		if(dist+paths[now][1] == k)ans++;
		return;
	}
	for(int i = 0;i<n;i++){
		if((1<<i)&mask)continue;
		dfs(i+1,mask^(1<<i),dist+paths[now][i+1]);
	}
	return;
}
int main(){
	io
	cin>>n>>k;
	for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++)cin>>paths[i][j];
	dfs(1,1,0);
	cout<<ans;
}

