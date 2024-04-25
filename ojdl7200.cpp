#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 5e5+10;
int n,q;
int dsu[mxn],sz[mxn];

ll sum = 0,cnt = 0;
vector<pll> v;
vector<pair<ll,pll>> edges;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
inline void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	cnt++;
	if(sz[a]<sz[b])swap(a,b);
	sum += 1ll*sz[a]*sz[b];
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	for(int i = 1;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		edges.push_back(make_pair(c,make_pair(a,b)));
	}
	sort(edges.begin(),edges.end());
	cnt = 0;
	for(auto &i:edges){
		onion(i.sc.fs,i.sc.sc);
		if(v.empty()||v.back().sc != i.fs)v.push_back(make_pair(sum-cnt,i.fs));
		else v.back().fs = sum-cnt;
	}
	//for(auto &i:v)cout<<i.sc<<' '<<i.fs<<endl;
	assert(v.back().fs == sum-(n-1));
	cin>>q;
	while(q--){
		ll k;
		cin>>k;
		auto it = lower_bound(v.begin(),v.end(),make_pair(k,-1ll));
		assert(it != v.end());
		cout<<it->sc<<'\n';
	}
	return 0;
}
