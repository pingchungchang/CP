#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
int bit[mxn];
pii range[mxn];
int dfn = 0;
int n;
ll root = 0;
vector<int> tree[mxn];
int idx[mxn];

inline void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}

inline int getval(int p){
	int re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

void dfs(int now){
	range[now].fs = ++dfn;
	for(auto nxt:tree[now]){
		dfs(nxt);
	}
	range[now].sc = dfn;
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int tmp;cin>>tmp;
			root += tmp;
			tree[i].push_back(tmp);
		}
	}
	root = 1LL*n*(n+1)/2-root;
	dfs(root);
	assert(n == dfn);
	while(q--){
		int t;
		cin>>t;
		if(!t){
			int p;
			cin>>p;
			modify(range[p].fs,1);
			modify(range[p].sc+1,-1);
		}
		else{
			int p;
			cin>>p;
			cout<<(getval(range[p].fs)&1)<<'\n';
		}
	}
	return 0;
}
