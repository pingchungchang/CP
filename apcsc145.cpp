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
const int mxn = 2e5+10;
struct edge{
	int a,b,c;
	edge(){
		a = b = c = 0;
	}
	bool operator<(const edge&b)const{
		return c<b.c;
	}
};
int dsu[mxn];
int root(int k){
	while(dsu[k] != k){
		dsu[k] = dsu[dsu[k]];
		k = dsu[k];
	}
	return k;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	edge edges[m];
	for(auto &i:edges){
		cin>>i.a>>i.b>>i.c;
	}
	sort(edges,edges+m);
	ll ans = 0;
	for(int i = 1;i<=n;i++)dsu[i] = i;
	for(auto &i:edges){
		if(root(i.a) == root(i.b))continue;
		dsu[root(i.a)] = root(i.b);
		ans += i.c;
	}
	cout<<ans;
}

