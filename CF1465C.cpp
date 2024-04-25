#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e5+10;
int dsu[mxn];
int sz[mxn];
int cnt[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	cnt[a] += cnt[b];
	sz[a] += sz[b];
	return;
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		cnt[i] = 0;
		sz[i] = 1;
	}
	int ans = 0;
	for(int i = 0;i<m;i++){
		pll tmp;
		cin>>tmp.fs>>tmp.sc;
		if(tmp.fs == tmp.sc)continue;
		ans++;
		onion(tmp.fs,tmp.sc);
		cnt[root(tmp.fs)]++;
	}
	for(int i = 1;i<=n;i++){
		//if(i == dsu[i])cout<<i<<":"<<sz[i]+1<<','<<cnt[i]<<' ';
		if(i == dsu[i]&&sz[i] == cnt[i])ans++;
	}
	cout<<ans;
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
