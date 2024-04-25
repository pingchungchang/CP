#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5050;
unordered_set<int> paths[mxn];
int deg[mxn];
bitset<mxn> done;
int n,m;
ll ans;
int dsu[mxn],sz[mxn];
bitset<mxn> dist[mxn];
vector<pii> v;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
inline void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	sz[a] += sz[b];
	dsu[b] = a;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		dist[a][b] = dist[b][a] = 1;
	}
	for(int i = 1;i<=n;i++)deg[i] = dist[i].count();
	for(int i = 1;i<=n;i++){
		pii small = {mxn,mxn};
		for(int j = 1;j<=n;j++)if(!done[j])small = min(small,make_pair(deg[j],j));
		v.push_back(small);
		for(int j = 1;j<=n;j++){
			if(dist[small.sc][j])deg[j]--;
		}
		done[small.sc] = true;
	}
	done.reset();
	reverse(v.begin(),v.end());
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	for(auto &i:v){
		//cout<<i.fs<<":"<<i.sc<<'\n';
		done[i.sc] = true;
		for(int j = 1;j<=n;j++){
			if(done[j]&&dist[i.sc][j])onion(i.sc,j);
		}
		ans = max(ans,1LL*i.fs*sz[root(i.sc)]);
	}
	cout<<ans;
}
