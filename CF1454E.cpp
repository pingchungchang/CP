#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn];
bool jelly[mxn];
int deg[mxn];
ll sz[mxn];
int n;

void dfs(int now,int par){
	sz[now] = 1;
	for(auto nxt:paths[now]){
		if(nxt == par||jelly[nxt])continue;
		dfs(nxt,now);
		sz[now] += sz[nxt];
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++)paths[i].clear();
	for(int i = 0;i<=n;i++){
		jelly[i] = true;
		deg[i] = sz[i] = 0;
	}
	cin>>n;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
		deg[a]++,deg[b]++;
	}
	queue<int> q;
	for(int i = 1;i<=n;i++)if(deg[i] == 1)q.push(i);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		jelly[now] = false;
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(deg[nxt] == 1)q.push(nxt);
		}
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++)if(jelly[i])dfs(i,i);
	for(int i = 1;i<=n;i++){
		if(!jelly[i])continue;
		ans += sz[i]*(sz[i]-1)/2;
		ans += sz[i]*(n-sz[i]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:jelly)i = true;
	int t;cin>>t;
	while(t--)solve();
}
