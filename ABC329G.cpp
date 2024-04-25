#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 998244353;
const int mxn = 1e4+10;
vector<int> tree[mxn];
ll ans = 1;
int dir[mxn];
int dp[mxn][1010];
int n,m,k;
int par[mxn][20],dep[mxn];
int op[mxn][2][2];//D1:0/1=+/-;D2:0/1=bef/aft
ll sum[mxn];

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}
inline int mub(int a,int b){
	return mad(a,mod-b);
}

void dfs1(int now){
	for(int i = 1;i<20;i++)par[now][i] = par[par[now][i-1]][i-1];
	for(auto nxt:tree[now]){
		par[nxt][0] = now;
		dep[nxt] = dep[now]+1;
		dfs1(nxt);
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
		if(par[a][i] != par[b][i])a = par[a][i],b = par[b][i];
	}
	return a==b?a:par[a][0];
}

void dfs2(int now){
	if(dir[now]==3)ans = 0;
	if(tree[now].empty())dp[now][op[now][0][0]+op[now][0][1]] = 1;
	for(auto nxt:tree[now])dfs2(nxt);
	if(tree[now].size() == 1){
		sum[now] = sum[nxt]+op[now][0][0]+op[now][0][1]-op[now][1][0]-op[now][1][1];
		for(int i = 0;i<=k;i++){
			int sh = op[now][0][0]-op[now][1][0];
			sh = max(0,sh);
			int tmp = max(sh+i,sum[now]);
		}
		for(int i = k+1;i<1010;i++)dp[now][i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		tree[p].push_back(i);
	}
	dfs1(1);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		int anc = lca(a,b);
		if(tree[anc].size()>=2){
			if(tree[anc][0] == a&&tree[anc][1] == b)dir[anc]|=1;
			else if(tree[anc][0] == b&&tree[anc][1] == b)dir[anc]|=2;
		}
		if(anc == a)op[a][0][0]++;
		else op[a][0][1]++;
		if(anc == b)op[b][1][1]++;
		else op[b][1][0]++;
	}
	dfs2(1);
}
