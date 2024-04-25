#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int dsu[mxn],sz[mxn];
pii edges[mxn];
set<int> st;
int deg[mxn];

int root(int k){
	return dsu[k] == k?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	sz[a] += sz[b];
	dsu[b] = a;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	for(int i = 1;i<=m;i++){
		cin>>edges[i].fs>>edges[i].sc;
	}
	int k;
	cin>>k;
	while(k--){
		int a;
		cin>>a;
		st.insert(a);
	}
	for(int i = 1;i<=m;i++){
		if(st.find(i) != st.end())continue;
		onion(edges[i].fs,edges[i].sc);
	}
	for(auto &i:st){
		deg[root(edges[i].fs)]++;
		deg[root(edges[i].sc)]++;
	}
	int od = 0;
	for(int i = 1;i<=n;i++){
		if(deg[i]&1)od++;
	}
	cout<<(od<=2?"Yes":"No");
}
