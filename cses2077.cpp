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

const int mxn = 1e5+10;
bitset<mxn> cut;
int idx[mxn];
int cnt = 1;
int low[mxn];
int ans[mxn];
int p = 0;
vector<int> paths[mxn];

void dfs(int now,int par){
	int c = 0;
	idx[now] = low[now] = cnt++;
	for(auto nxt:paths[now]){
		if(nxt == par)continue;
		if(idx[nxt]){
			low[now] = min(low[now],idx[nxt]);
		}
		else{
			c++;
			dfs(nxt,now);
			low[now] = min(low[now],low[nxt]);
			if(par != -1&&low[nxt]>=idx[now])cut[now] = true;
		}
	}
	if(par == -1&&c>1)cut[now] = true;
	return;
}
int main(){
	io
	cut.reset();
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	dfs(1,-1);
	for(int i =1;i<=n;i++){
		if(cut[i])ans[p++] = i;
	}
//	for(int i =1 ;i<=n;i++)cout<<idx[i]<<' ';cout<<endl;
//	for(int i = 1;i<=n;i++)cout<<low[i]<<' ';cout<<endl;
	cout<<p<<'\n';
	for(int i = 0;i<p;i++)cout<<ans[i]<<' ';
}

