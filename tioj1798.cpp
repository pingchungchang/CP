#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;

int dep[mxn],fa[mxn],dsu[mxn],sz[mxn],high[mxn];
vector<int> tree[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
inline void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	dsu[b] = a;
	sz[a] += sz[b];
	if(dep[high[b]]<dep[high[a]])high[a] = high[b];
	return;
}

void dfs(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		fa[nxt] = now;
		dfs(nxt,now);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	for(int i = 1;i<=n;i++){
		high[i] = dsu[i] = i;
		sz[i] = 1;
	}
	for(int i = 0;i<k;i++){
		int a,b;
		cin>>a>>b;
		a = root(a),b = root(b);
		while(a != b){
			if(dep[high[a]]<dep[high[b]])swap(a,b);
			onion(a,fa[high[a]]);
			a = root(a);
			b = root(b);
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		if(root(a) == root(b))cout<<1<<'\n';
		else cout<<"0\n";
	}
	return 0;
}
