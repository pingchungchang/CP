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
vector<tlll> edges;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	dsu[root(a)] = root(b);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<=n;i++)dsu[i] = i;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back(make_tuple(c,a,b));
	}
	sort(edges.begin(),edges.end());
	ll ans = 0;
	for(auto &i:edges){
		if(get<0>(i)>0&&root(get<1>(i)) == root(get<2>(i)))continue;
		ans += get<0>(i);
		onion(get<1>(i),get<2>(i));
	}
	cout<<ans;
}
