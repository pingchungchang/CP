#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> tree[mxn];
int dp[mxn];
int ans = 0;
int mid = 0;
bool flag = false;

void dfs(int now,int par){
	dp[now] = mxn;
	pair<int,int> p = {0,0};
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		dp[now] = min(dp[now],dp[nxt]+1);
		if(dp[nxt]>=p.fs)swap(p.fs,p.sc),p.fs = dp[nxt];
		else if(dp[nxt]>=p.sc)p.sc = dp[nxt];
	}
	if(p.sc+1>mid)flag = false;
	if(p.fs>mid)flag = false;
	else if(p.fs+1>mid)dp[now] = p.fs+1;
	if(dp[now] == mxn)dp[now] = 1;
	return;
}


void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	ans = 0;
	int l = 1,r = n;
	while(l != r){
		mid = (l+r)>>1;
		flag = true;
		dfs(1,1);
		if(flag)r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
	for(int i = 0;i<=n;i++)tree[i].clear(),dp[i] = mxn;
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
