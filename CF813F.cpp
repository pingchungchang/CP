#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int N,Q;

struct DSU{
	int dsu[mxn],sz[mxn];
	vector<pii> sop,dop;
	void init(int n){
		for(int i = 0;i<=n;i++)dsu[i] = i,sz[i] = 1;
	}
	int root(int k){
		return k==dsu[k]?k:root(dsu[k]);
	}
	void onion(int a,int b){
		a = root(a),b = root(b);
		if(a==b){
			sop.push_back(pii(0,0));
			dop.push_back(pii(0,0));
			return;
		}
		if(sz[a]<sz[b])swap(a,b);
		sop.push_back(pii(a,sz[a]));
		dop.push_back(pii(b,b));
		dsu[b] = a;
		sz[a] += sz[b];
		return;
	}
	void roll(){
		auto [a,b] = sop.back();sop.pop_back();
		sz[a] = b;
		auto [c,d] = dop.back();dop.pop_back();
		dsu[c] = c;
		return;
	}
};

DSU dsu;
vector<pii> seg[mxn*4];
map<pii,int> mp;
bitset<mxn> ans;

void modify(int now,int l,int r,int s,int e,pii v){
	if(l>=s&&e>=r){
		seg[now].push_back(v);
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	return;
}

void dfs(int now,int l,int r,bool flag = true){
	for(auto &[a,b]:seg[now]){
		dsu.onion(a,b+N);
		dsu.onion(b,a+N);
		if(dsu.root(a+N) == dsu.root(a) || dsu.root(b) == dsu.root(b+N))flag = false;
	}
	if(l == r)ans[l] = flag;
	else{
		int mid = (l+r)>>1;
		dfs(now*2+1,l,mid,flag);
		dfs(now*2+2,mid+1,r,flag);
	}
	for(auto &i:seg[now]){
		dsu.roll();
		dsu.roll();
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	dsu.init(N*2);
	for(int i = 1;i<=Q;i++){
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		if(mp.find(pii(a,b)) != mp.end()){
			modify(0,1,Q,mp[pii(a,b)],i-1,pii(a,b));
			mp.erase(pii(a,b));
		}
		else mp[pii(a,b)] = i;
	}
	for(auto &i:mp)modify(0,1,Q,i.sc,Q,i.fs);
	dfs(0,1,Q);
	for(int i = 1;i<=Q;i++){
		cout<<(ans[i]?"YES\n":"NO\n");
	}
	assert(dsu.sop.empty());
	return 0;
}
