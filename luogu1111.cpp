#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tiii tuple<int,int,int>
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;

struct DSU{
	int dsu[mxn],sz[mxn];
	DSU(){
		for(int i = 0;i<mxn;i++)dsu[i] = i,sz[i] = 1;
	}
	int root(int k){
		return k == dsu[k]?k:dsu[k] = root(dsu[k]);
	}
	void onion(int a,int b){
		a = root(a),b = root(b);
		if(a == b)return;
		if(sz[a]<sz[b])swap(a,b);
		dsu[b] = a;
		sz[a] += sz[b];
		return;
	}
};

DSU dsu;
vector<tiii> edges;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back(make_tuple(c,a,b));
	}
	sort(edges.begin(),edges.end());
	for(auto &i:edges){
		dsu.onion(get<1>(i),get<2>(i));
		if(dsu.sz[dsu.root(get<1>(i))] == n){
			cout<<get<0>(i);
			exit(0);
		}
	}
	cout<<-1;
}
