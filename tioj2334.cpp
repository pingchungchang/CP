#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>

const int mxn = 1010;

bitset<mxn> vis;
vector<int> tree[mxn];
int dsu[mxn],sz[mxn],dep[mxn];
int par[mxn],low[mxn];
vector<pii> req[mxn];
int ans[mxn*mxn];
vector<tiii> edges,nottree;
int n,m;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

inline void onion(int a,int b,int w = 0){
	a = root(a),b = root(b);
	if(req[a].size()<req[b].size()){
		swap(a,b);
	}
	while(!req[b].empty()){
		auto tmp = req[b].back();
		//cout<<a<<" merge "<<b<<":"<<tmp.fs<<','<<root(tmp.fs)<<endl;
		req[b].pop_back();
		if(root(tmp.fs) == a){
			if(ans[tmp.sc] == 0){
				ans[tmp.sc] = w;
			}
		}
		else{
			req[a].push_back(tmp);
		}
	}
	if(sz[a]<sz[b]){
		req[a].swap(req[b]);
		swap(a,b);
	}
	if(dep[low[b]]<dep[low[a]])low[a] = low[b];
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

queue<int> qq;
void dfs(int now){
	vis[now] = true;
	dep[now] = 0;
	qq.push(now);
	while(!qq.empty()){
		auto now = qq.front();
		q.pop();
		for(auto nxt:tree[now]){
			if(vis[nxt])continue;
			vis[nxt] = true;
			dep[nxt] = dep[now]+1;
			q.push(nxt);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		tiii tmp;
		cin>>get<1>(tmp)>>get<2>(tmp)>>get<0>(tmp);
		edges.push_back(tmp);
	}
	for(int i = 1;i<=n;i++)sz[i] = 1,dsu[i] = i;
	sort(edges.begin(),edges.end());
	for(auto &i:edges){
		int a = get<1>(i),b = get<2>(i);
		if(root(a) == root(b))nottree.push_back(i);
		else{
			onion(a,b);
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
	}


	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		if(root(a) != root(b))ans[i] = -1;
		else{
			req[a].push_back({b,i});
			req[b].push_back({a,i});
		}
	}

	for(int i = 1;i<=n;i++){
		if(!vis[i])dfs(i);
	}
	for(int i = 1;i<=n;i++)dsu[i] = i,low[i] = i,sz[i] = 1;
	for(auto &i:nottree){
		int a = get<1>(i),b = get<2>(i),w = get<0>(i);
		//cout<<a<<' '<<b<<":"<<w<<endl;
		a = low[root(a)],b = low[root(b)];
		while(a != b){
			if(dep[a]<dep[b])swap(a,b);
			onion(a,par[a],w);
			a = low[root(a)];
		}
		//for(int i = 1;i<=n;i++)cout<<low[root(i)]<<' ';cout<<endl;
	}
	for(int i = 0;i<q;i++)if(!ans[i])ans[i] = -1;
	for(int i = 0;i<q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

