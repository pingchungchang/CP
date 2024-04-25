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

const int mxn = 1e5+10;
vector<pll> tree[mxn];
bitset<mxn> cols;
void dfs(int now,int par){
	for(auto &i:tree[now]){
		int nxt = i.fs;
		if(nxt != par){
			if(i.sc&1)cols[nxt] = !cols[now];
			else cols[nxt] = cols[now];
			dfs(nxt,now);
		}
	}
	return;
}
int main(){
	io
	int n;
	cin>>n;
	for(int i = 0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
	}
	dfs(1,1);
	for(int i = 1;i<=n;i++)cout<<cols[i]<<'\n';
	return 0;
}

