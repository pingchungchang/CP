#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>

const ll inf = 2e9;
const int mxn = 4e5+10;
int n,m;
vector<tiii> edges;

namespace DIJ{
	int dist[mxn];
	vector<pii> paths[mxn];
	void DO(){
		for(auto &i:dist)i = inf;
		dist[1] = 0;
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		pq.push(make_pair(0,1));
		while(!pq.empty()){
			auto now = pq.top();
			pq.pop();
			if(now.fs != dist[now.sc])continue;
			for(auto nxt:paths[now.sc]){
				if(dist[nxt.fs]>nxt.sc+dist[now.sc]){
					dist[nxt.fs] = nxt.sc+dist[now.sc];
					pq.push(make_pair(dist[nxt.fs],nxt.fs));
				}
			}
		}
		return;
	}
}

namespace DSU{
	int dsu[mxn],sz[mxn], head[mxn];
	int root(int k){
		return k==dsu[k]?k:dsu[k] = root(dsu[k]);
	}
	void onion(int a,int b){
		a = root(a),b = root(b);
		if(sz[a]<sz[b])swap(a,b);
		dsu[b] = a;
		sz[a] += sz[b];
		return;
	}
}

namespace KRUS{
	vector<int> tree[mxn];
	vector<tiii> edges;
	int val[mxn];
	int ppp = 0;
	int dp[mxn];
	pii par[20][mxn];
	int r;
	void dfs(int now){
		dp[now] = DIJ::dist[now];
		for(int i = 1;i<20;i++){
			par[i][now].fs = par[i-1][par[i-1][now].fs].fs;
			par[i][now].sc = par[i-1][par[i-1][now].fs].sc;
		}
		for(auto nxt:tree[now]){
			dfs(nxt);
			dp[now] = min(dp[now],dp[nxt]);
		}
		return;
	}
	int newnode(){
		return ++ppp;
	}
	void DO(){
		for(auto &i:val)i = inf;
		sort(edges.rbegin(),edges.rend());
		for(int i = 0;i<mxn;i++){
			DSU::dsu[i] = DSU::head[i] = i;
			DSU::sz[i] = 1;
		}
		ppp = n;
		for(auto &i:edges){
			int a = get<1>(i),b = get<2>(i);
			assert(a<mxn&&b<mxn);
			a = DSU::root(a),b = DSU::root(b);
			if(a == b)continue;
			r = newnode();
			DSU::onion(a,b);
			int ha = DSU::head[a],hb = DSU::head[b];
			//cout<<a<<' '<<b<<' '<<r<<endl;
			par[0][ha] = par[0][hb] = par[0][r] = {r,get<0>(i)};
			tree[r].push_back(ha);tree[r].push_back(hb);
			val[r] = get<0>(i);
			DSU::head[DSU::root(a)] = r;
		}
		//cout<<r<<endl<<endl;
		dfs(r);
	}
	void print(){
		for(int i = 1;i<=ppp;i++){
			cout<<i<<":"<<dp[i]<<','<<val[i]<<":";for(auto &j:tree[i])cout<<j<<',';cout<<endl;
		}
	}
}

void init(){
	KRUS::edges.clear();
	for(auto &i:DIJ::paths)i.clear();
	for(auto &i:KRUS::tree)i.clear();
	return;
}

void solve(){
	init();
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		DIJ::paths[a].push_back({b,c});
		DIJ::paths[b].push_back({a,c});
		KRUS::edges.push_back(make_tuple(d,a,b));
	}
	DIJ::DO();
	KRUS::DO();
	//KRUS::print();
	int Q,K,S;
	cin>>Q>>K>>S;
	int pre = 0;
	while(Q--){
		int a,b;
		cin>>a>>b;
		a = (a+K*pre-1)%n+1,b = (b+K*pre)%(S+1);
		for(int i = 19;i>=0;i--){
			if(KRUS::par[i][a].sc>b)a = KRUS::par[i][a].fs;
		}
		cout<<(pre = KRUS::dp[a])<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
