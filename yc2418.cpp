#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int dsu[mxn],sz[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
inline void onion(int a,int b){
	a  = root(a),b = root(b);
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
	for(int i = 1;i<=n*2;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		onion(a,b);
	}
	ll ans = n;
	for(int i = 1;i<=n*2;i++){
		if(i == dsu[i])ans -= sz[i]/2;
	}
	cout<<ans;
}
