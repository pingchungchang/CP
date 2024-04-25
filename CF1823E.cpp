#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
int dsu[mxn],sz[mxn];
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

void solve(){
	int n,l,r;
	cin>>n>>l>>r;
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		onion(a,b);
	}
	int sg = 0;
	for(int i = 1;i<=n;i++){
		if(dsu[i] != i)continue;
		if(sz[i]<r+l)sg ^= sz[i]/l;
	}
	if(!sg)cout<<"Bob\n";
	else cout<<"Alice\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
