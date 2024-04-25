#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int dsu[mxn],sz[mxn];
pii dp[mxn];
int n,m;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
inline void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dp[a].fs = min(dp[a].fs,dp[b].fs);
	dp[a].sc = max(dp[a].sc,dp[b].sc);
	sz[a] += sz[b];
	dsu[b] = a;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
		dp[i] = {i,i};
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		onion(a,b);
	}
	vector<pii> v;
	for(int i = 1;i<=n;i++){
		if(dsu[i] == i)v.push_back(dp[i]);
	}
	sort(v.begin(),v.end());
	int ans = 0;
	int r = v[0].sc;
	for(int i = 1;i<v.size();i++){
		if(r>v[i].fs){
			r = max(r,v[i].sc);
			ans++;
		}
		else r = v[i].sc;
	}
	cout<<ans;
}
