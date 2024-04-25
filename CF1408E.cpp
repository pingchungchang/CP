#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<pair<int,pii>> paths;
int dsu[mxn],sz[mxn];

int root(int k){
	return k==dsu[k]?k:dsu[k] = root(dsu[k]);
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
	ll total = 0;
	cin>>m>>n;
	int arr[m+1],brr[n+1];
	for(int i = 1;i<=m;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>brr[i];
	}
	for(int i = 1;i<=m;i++){
		int k;
		cin>>k;
		while(k--){
			int tmp;
			cin>>tmp;
			paths.push_back({arr[i]+brr[tmp],{tmp,i+n}});
			total += arr[i]+brr[tmp];
		}
	}
	sort(paths.rbegin(),paths.rend());
	for(int i = 1;i<mxn;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	ll ans = 0;
	for(auto &i:paths){
		if(root(i.sc.fs) == root(i.sc.sc))continue;
		onion(i.sc.fs,i.sc.sc);
		ans += i.fs;
	}
	cout<<total-ans;
}
