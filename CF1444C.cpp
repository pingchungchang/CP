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
	int sz[mxn],dsu[mxn];
	vector<pii> sop,dop;
	DSU(){}
	void init(int n){
		for(int i = 0;i<=n;i++)dsu[i] = i,sz[i] = 1;
	}
	int root(int k){
		return k==dsu[k]?k:root(dsu[k]);
	}
	void onion(int a,int b,bool rec = false){
		a = root(a),b = root(b);
		if(sz[a]<sz[b])swap(a,b);
		if(rec){
			sop.push_back(pii(a,sz[a]));
			dop.push_back(pii(b,b));
		}
		dsu[b] = a;
		sz[a] += sz[b];
	}
	void roll(){
		while(!sop.empty()){
			auto [a,b] = sop.back();sop.pop_back();
			sz[a] = b;
		}
		while(!dop.empty()){
			auto [a,b] = dop.back();dop.pop_back();
			dsu[a] = b;
		}
		return;
	}
};

map<pii,vector<pii>> edges;
int arr[mxn];
int N,M,K;
DSU dsu;
bitset<mxn> bip;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>K;
	dsu.init(N*2);
	for(int i = 1;i<=N;i++)cin>>arr[i];
	for(int i = 1;i<=K;i++)bip[i] = true;
	for(int i = 0;i<M;i++){
		int a,b;
		cin>>a>>b;
		if(arr[a] == arr[b]){
			dsu.onion(a,b+N);
			dsu.onion(b,a+N);
			if(dsu.root(a) == dsu.root(a+N)||dsu.root(b) == dsu.root(b+N))bip[arr[a]] = false;
		}
		else{
			if(arr[a]>arr[b])swap(a,b);
			edges[pii(arr[a],arr[b])].push_back(pii(a,b));
		}
	}
	ll C = bip.count();
	ll ans = C*(C-1)>>1;
	for(auto &i:edges){
		if(!bip[i.fs.fs]||!bip[i.fs.sc])continue;
		bool flag = true;
		for(auto &[a,b]:i.sc){
			dsu.onion(a,b+N,1);
			dsu.onion(b,a+N,1);
			if(dsu.root(a) == dsu.root(a+N))flag = false;
			if(dsu.root(b) == dsu.root(b+N))flag = false;
		}
		if(!flag)ans--;
		dsu.roll();
	}
	cout<<ans<<'\n';
}
