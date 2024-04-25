#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;

struct DSU{
	int cc;
	int dsu[mxn],sz[mxn];
	DSU(){cc = 0;}
	void init(int n){
		for(int i = 1;i<=n;i++){
			dsu[i] = i;
			sz[i] = 1;
			cc++;
		}
		return;
	}
	int root(int k){
		return k == dsu[k]?k:dsu[k] = root(dsu[k]);
	}
	void onion(int a,int b){
		a = root(a),b = root(b);
		if(a == b)return;
		dsu[b] = a;
		sz[a]++;
		cc--;
		return;
	}
};

vector<int> v[3];
pii tree[mxn];
int N,Q;
DSU dsu;

void dfs(int now){
	if(!now)return;
	v[0].push_back(now);
	dfs(tree[now].fs);
	v[1].push_back(now);
	dfs(tree[now].sc);
	v[2].push_back(now);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	dsu.init(N);
	for(int i = 2;i<=N;i++){
		int p,t;
		cin>>p>>t;
		if(!t)tree[p].fs = i;
		else tree[p].sc = i;
	}
	dfs(1);
	for(auto &nv:v){
		for(int i = 0;i+i<nv.size();i++){
			dsu.onion(nv[i],nv.end()[-1-i]);
		}
	}
	cout<<dsu.cc<<'\n';
	while(Q--){
		int a,b;
		cin>>a>>b;
		dsu.onion(a,b);
		cout<<dsu.cc<<'\n';
	}
	return 0;
}
