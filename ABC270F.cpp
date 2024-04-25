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
int arr[mxn],brr[mxn];
vector<tlll> edges;

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

ll _span(vector<tlll> v){
	sort(v.begin(),v.end());
	ll re = 0;
	for(int i = 0;i<mxn;i++){
		dsu[i] = i;
		sz[i] = 1;
	}
	for(auto &i:v){
		ll ta = get<1>(i),tb = get<2>(i),val = get<0>(i);
		if(root(ta) != root(tb))re += val;
		onion(ta,tb);
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>brr[i];
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back(make_tuple(c,a,b));
	}
	ll ans = 4e18;
	ll re = _span(edges);
	if(sz[root(1)] == n)ans = min(ans,re);
	for(int i = 1;i<=n;i++)edges.push_back(make_tuple(arr[i],i,n+1));
	ans = min(ans,_span(edges));
	for(int i = 1;i<=n;i++)get<0>(edges[i+m-1]) = brr[i];
	ans = min(ans,_span(edges));
	for(int i = 1;i<=n;i++)edges.push_back(make_tuple(arr[i],i,n+2));
	ans = min(ans,_span(edges));
	cout<<ans<<'\n';
	return 0;
}
