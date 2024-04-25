#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
int par[mxn][20],dep[mxn];
vector<int> tree[mxn];

void dfs(int now){
	for(int i = 1;i<20;i++){
		par[now][i] = par[par[now][i-1]][i-1];
	}
	for(auto nxt:tree[now]){
		if(nxt == par[now][0])continue;
		dep[nxt] = dep[now]+1;
		par[nxt][0] = now;
		dfs(nxt);
	}
	return;
}

int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int d = dep[a]-dep[b];
	for(int i = 19;i>=0;i--){
		if(d&(1<<i))a = par[a][i];
	}
	for(int i = 19;i>=0;i--){
		if(par[a][i] != par[b][i]){
			a = par[a][i],b = par[b][i];
		}
	}
	if(a == b)return a;
	else return par[a][0];
}

int find(int a,int k){
	for(int i = 19;i>=0;i--){
		if(k&(1<<i))a = par[a][i];
	}
	return a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	par[1][0] = 1;
	dfs(1);
	while(q--){
		int a,b,k;
		cin>>a>>b>>k;
		int c = lca(a,b);
		if(dep[a]+dep[b]-dep[c]*2<k){
			cout<<"-1\n";
			continue;
		}
		if(dep[a]-dep[c]>=k){
			cout<<find(a,k)<<'\n';
		}
		else{
			k -= dep[a]-dep[c];
			k = dep[b]-dep[c]-k;
			cout<<find(b,k)<<'\n';
		}
	}
	return 0;
}
