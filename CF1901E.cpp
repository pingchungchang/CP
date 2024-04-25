#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

vector<int> tree[mxn],tree2[mxn];
ll dp[mxn],dp2[mxn];
ll arr[mxn];
int n;
vector<pii> chain;
bitset<mxn> chain;
bitset<mxn> vis;

void dfs1(int now,int par){
	vis[now] = true;
	dp[now] = -1e9;
	vector<ll> sons;
	for(auto nxt:tree2[now]){
		dfs1(nxt,now);
		sons.push_back(tree[nxt]);
	}
	assert(sons.size() != 1);
	if(sons.empty())dp[now] = arr[now];
	else{
		sort(sons.rbegin(),sons.rend());
		ll sum = sons[0]+sons[1]+arr[now];
		for(int i = 2;i<sons.size()&&sons[i]>0;i++)sum += sons[i];
		dp[now] = max({sum,sons[0],arr[now]});
	}
	return;
}

void dfs2(int now,int par){
	if(now != par){
		vector<ll> sons;
		for(auto nxt:tree2[now]){
			sons.push_back(tree[nxt]);
		}
		assert(sons.size() != 1);
		if(sons.empty())dp[now] = arr[now];
		else{
			sort(sons.rbegin(),sons.rend());
			ll sum = sons[0]+sons[1]+arr[now];
			for(int i = 2;i<sons.size()&&sons[i]>0;i++)sum += sons[i];
			dp2[now] = max({sum,sons[0],arr[now]});
		}
	}
	else dp2[now] = dp[now];
	vector<ll> sons;
	for(auto nxt:tree2[now]){
		sons.push_back(dp[nxt]);
	}
	sort(sons.rbegin(),sons.rend());
	if(sons.size() == 1){
		dp[now] = arr[now];
		for(auto nxt:tree2[now]){
			if(nxt == par)continue;
			dfs(nxt,now);
		}
	}
	else{
		ll sum = arr[now]+sons[0]+sons[1];
		for(int i = 2;i<sons.size()&&sons[i]>0;i++)sum += sons[i];
		for(auto nxt:tree2[now]){
			if(nxt == par)continue;
			ll tmp = max(arr[now],(sons[0] == dp[nxt]?sons[1]:sons[0]));
			if(dp[nxt]>0)tmp = max(tmp,sum-dp[nxt]);
			else if(dp[nxt] == sons[0]||dp[nxt] == sons[1])tmp = max(tmp,sum-dp[nxt]+sons[2]);
			else tmp = max(tmp,sum);
			swap(dp[now],tmp);
			dfs(nxt,now);
			swap(dp[now],tmp);
		}
	}
	return;
}

void solve(){
	ans = 0;
	for(int i = 0;i<=n;i++){
		vis[i] = chain[0] = false;
		tree[i].clear();
		tree2[i].clear();
	}
	chain.clear();
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		if(tree[i].size() == 2){
			chain[i] = true;
			continue;
		}
		for(auto nxt:tree[i]){
			if(tree[nxt].size() != 2){
				tree2[i].push_back(nxt);
				tree2[nxt].push_back(i);
			}
		}
	}
	int rt = 1;
	while(tree[rt].size() == 2)rt++;
	for(int i = 1;i<=n;i++){
		if(chain[i]||vis[i])continue;
		dfs1(i,i);
		dfs2(i,i);
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
