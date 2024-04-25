#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
int deg[mxn];
int dsu[mxn];
int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)dsu[i] = i;
	while(m--){
		int a,b;
		cin>>a>>b;
		if(root(a) == root(b)){
			cout<<"No";
			return 0;
		}
		dsu[root(a)] = root(b);
		deg[a]++;
		deg[b]++;
	}
	int sm = 0;
	for(int i = 1;i<=n;i++)sm += (deg[i]<2);
	for(int i = 1;i<=n;i++){
		if(deg[i]>2){
			cout<<"No";
			return 0;
		}
	}
	if(sm>=2)cout<<"Yes";
	return 0;
}
