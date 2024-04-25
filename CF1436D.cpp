#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
const ll inf = 1e15;
int val[mxn];
int sz[mxn];
ll dp[mxn];
vector<int> tree[mxn];
ll tar;

bool dfs(int now){
	if(tree[now].empty())sz[now] = 1;
	else sz[now] = 0;
	dp[now] = val[now];
	bool flag = true;
	for(auto nxt:tree[now]){
		flag &= dfs(nxt);
		dp[now] += dp[nxt];
		sz[now] += sz[nxt];
	}
	if((dp[now]+sz[now]-1)/sz[now]>tar)flag = false;
	return flag;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		tree[p].push_back(i);
	}
	for(int i = 1;i<=n;i++)cin>>val[i];
	ll l = *min_element(val,val+n+1),r = inf;
	while(l != r){
		ll mid = (l+r)>>1;
		tar = mid;
		if(dfs(1))r = mid;
		else l = mid+1;
	}
	cout<<l;
}
