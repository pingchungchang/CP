#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2023;
int dsu[mxn],sz[mxn];
vector<int> paths[mxn];
int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,d;
	cin>>n>>d;
	pll arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 1;i<=n;i++)dsu[i] = i,sz[i] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if((arr[i].fs-arr[j].fs)*(arr[i].fs-arr[j].fs)+(arr[i].sc-arr[j].sc)*(arr[i].sc-arr[j].sc) <= d*d){
				onion(i,j);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(root(i) == root(1)){
			cout<<"Yes\n";
		}
		else cout<<"No\n";
	}
	return 0;
}
