#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int n,k;
const int mxn = 2e5+10;
vector<int> tree[mxn];
int sz[mxn],dep[mxn];
priority_queue<ll,vector<ll>,less<ll>> pq;

void dfs(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dep[nxt] = dep[now]+1;
		dfs(nxt,now);
		sz[now] += sz[nxt];
	}
	pq.push(dep[now]-sz[now]+1);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i<n;i++){
		int a,b;cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	ll ans = 0;
	for(int i = 0;i<k;i++){
		ans += pq.top();
		pq.pop();
	}
	cout<<ans;
}
