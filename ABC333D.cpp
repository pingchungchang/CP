#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
vector<int> tree[mxn];
int sz[mxn];
int n;

void dfs(int now,int par){
	sz[now] = 1;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		sz[now] += sz[nxt];
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	int ans = n;
	for(auto nxt:tree[1]){
		ans = min(ans,n-sz[nxt]);
	}
	cout<<ans;
}
