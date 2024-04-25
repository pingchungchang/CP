#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<int> tree[mxn];
int dist[mxn];
int n,a,b,da,db;

void dfs(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dist[nxt] = dist[now]+1;
		dfs(nxt,now);
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++)tree[i].clear();
	cin>>n>>a>>b>>da>>db;
	for(int i = 1;i<n;i++){
		int x,y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	if(da*2>=db){
		cout<<"Alice\n";
		return;
	}
	dist[1] = 0;
	dfs(1,1);
	pair<int,int> p = {0,1};
	for(int i = 1;i<=n;i++){
		p = max(p,make_pair(dist[i],i));
	}
	dist[p.sc] = 0;
	dfs(p.sc,p.sc);
	int r = 0;
	for(int i = 1;i<=n;i++){
		r = max(r,dist[i]);
	}
	if(da>=(r+1)/2){
		cout<<"Alice\n";
		return;
	}
	dist[a] = 0;
	dfs(a,a);
	if(dist[b]<=da){
		cout<<"Alice\n";
		return;
	}
	cout<<"Bob\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
