#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int n,m;
const int mxn = 1e5+10;
int deg[mxn];
vector<int> paths[mxn];
bitset<mxn> vis;
int dsu[mxn],sz[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		sz[i] = 1;
		dsu[i] = i;
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		deg[b]++;
		onion(a,b);
	}
	int ans = n;
	for(int i = 1;i<=n;i++){
		if(dsu[i] == i)ans--;
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	for(int i = 1;i<=n;i++){
		if(!vis[root(i)]&&deg[i]){
			ans += vis[root(i)] = true;
		}
	}
	cout<<ans;
}
