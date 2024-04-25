#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 2e5+10;
int dsu[mxn],sz[mxn];
set<pii> st;

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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)dsu[i] = i,sz[i] = 1;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		onion(a,b);
	}
	int k;
	cin>>k;
	bool flag = true;
	while(k--){
		int a,b;
		cin>>a>>b;
		a = root(a),b = root(b);
		if(a>b)swap(a,b);
		st.insert({a,b});
		if(a == b)flag = false;
	}
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		a = root(a),b = root(b);
		if(a>b)swap(a,b);
		if(!flag||st.find({a,b}) != st.end()){
			cout<<"No\n";
		}
		else cout<<"Yes\n";
	}
}
