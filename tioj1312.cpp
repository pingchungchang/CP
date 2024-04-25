#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int n,m;
const int mxn = 1e4+10;
int dsu[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a>b)swap(a,b);
	dsu[b] = a;
	return;
}
void solve(){
	for(int i = 1;i<=n;i++)dsu[i] = i;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		onion(a,b);
	}
	int k;
	cin>>k;
	cout<<root(k)<<'\n';
	return;
}
int main(){
	io
	while(cin>>n>>m){
		solve();
	}
}

