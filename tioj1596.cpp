#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
vector<pair<int,pii>> edges;
int n,m;
int dsu[mxn],sz[mxn],tag[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	tag[a] |= tag[b];
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
		tag[i] = 0;
	}
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back(make_pair(c,make_pair(a,b)));
	}
	sort(edges.rbegin(),edges.rend());
	int k;
	cin>>k;
	for(int i = 0;i<k;i++){
		int tmp;
		cin>>tmp;
		tag[tmp] = 1;
	}
	ll ans = 0;
	for(auto &i:edges){
		if(tag[root(i.sc.fs)]&&tag[root(i.sc.sc)]){
			ans += i.fs;
			continue;
		}
		onion(i.sc.fs,i.sc.sc);
	}
	cout<<ans;
}
