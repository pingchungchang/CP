#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


struct Edge{
	int id,a,b;
	Edge(){
		id = a = b = 0;
	}
};

const int mxn = 1e5+10;
int dsu[mxn],sz[mxn],low[mxn],idx[mxn];
vector<pii> paths[mxn];
map<int,vector<Edge>> mp;
vector<int> ans;
int n,m;
vector<int> all;
int C = 0;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
inline void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

void dfs(int now,int from = 0){
	idx[now] = low[now] = ++C;
	for(auto nxt:paths[now]){
		if(nxt.sc == from)continue;
		if(idx[nxt.fs]){
			low[now] = min(low[now],low[nxt.fs]);
		}
		else{
			dfs(nxt.fs,nxt.sc);
			low[now] = min(low[now],low[nxt.fs]);
		}
	}
	if(low[now] == idx[now]&&from)ans.push_back(from);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		Edge tmp;
		int w;
		cin>>tmp.a>>tmp.b>>w;
		tmp.id = i;
		mp[w].push_back(tmp);
	}
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	for(auto &i:mp){
		C = 0;
		all.clear();
		for(auto &j:i.sc){
			j.a = root(j.a);
			j.b = root(j.b);
			if(j.a == j.b)continue;
			//cout<<j.a<<' '<<j.b<<',';
			paths[j.a].push_back({j.b,j.id});
			paths[j.b].push_back({j.a,j.id});
		}
		for(auto &j:i.sc){
			if(j.a == j.b)continue;
			if(!idx[j.a])dfs(j.a);
		}
		//cout<<endl;
		for(auto &j:i.sc){
			if(j.a == j.b)continue;
			paths[j.a].clear();
			paths[j.b].clear();
			idx[j.a] = idx[j.b] = low[j.a] = low[j.b] = 0;
			onion(j.a,j.b);
		}
	}
	cout<<ans.size()<<'\n';
	sort(ans.begin(),ans.end());
	if(ans.empty())cout<<"0\n";
	else for(auto &i:ans)cout<<i<<' ';
}
