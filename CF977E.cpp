#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn];
int dsu[mxn],sz[mxn];
bitset<mxn> no;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

inline void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	sz[a] += sz[b];
	dsu[b] = a;
	no[a] = no[a]|no[b];
	return;
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		dsu[i] = i,sz[i] = 1;
		if(paths[i].size() != 2)no[i] = true;
	}
	for(int i =1;i<=n;i++){
		for(auto &j:paths[i]){
			onion(i,j);
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(dsu[i] == i&&!no[i])ans++;
	}
	cout<<ans;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
