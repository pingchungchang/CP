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
#pragma GCC optimize("O3")

const int mxn = 1e5+10;
vector<int> paths[mxn];
int ans = 0;

int dfs(int now,int par){
	int d1 = 0,d2 = 0;
	for(auto nxt:paths[now]){
		if(nxt == par)continue;
		int k = dfs(nxt,now);
		if(k>d1){
			swap(d1,d2);
			d1 = k;
		}
		else if(k>d2)d2 = k;
	}
	ans = max(ans,d1+d2+1);
	return d1+1;
}
int n;
void solve(){
	io
	ans = 0;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	dfs(0,0);
	cout<<ans-1<<'\n';
	for(int i = 0;i<n;i++)paths[i].clear();
	return;
}

int main(){
	io
	while(cin>>n)solve();
}

