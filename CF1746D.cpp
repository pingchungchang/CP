#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 2e5+10;

multiset<ll> st[mxn];
ll ans;
ll arr[mxn];
vector<int> tree[mxn];
ll n;

void merge(int a,int b){
	st[a].insert(*st[b].rbegin()+arr[b]);
	return;
	/*
	if(st[a].size()>st[b].size()){
		for(auto &i:st[b]){
			st[a].insert(i+dp[b]);
		}
	}
	else{
		swap(st[a],st[b]);
		dp[a] += dp[b];
		for(auto &i:st[b])st[a].insert(i-dp[b]);
	}
	return;

   */
}

void dfs(int now,ll k){
	ans += arr[now]*k;
	ll d;
	if(tree[now].size())d = k/tree[now].size();
	else{
		st[now].insert(0);
		return;
	}
	k %= tree[now].size();
	for(auto nxt:tree[now]){
		dfs(nxt,d);
		merge(now,nxt);
	}
	//cout<<now<<":";for(auto &i:st[now])cout<<i<<',';cout<<endl;
	while(k--){
		if(st[now].empty())exit(0);
		ans += *st[now].rbegin();
		st[now].erase(st[now].find(*st[now].rbegin()));
	}
	st[now].insert(0);
	return;
}
void init(){
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		st[i].clear();
	}
}

void solve(){
	ans = 0;
	ll k;
	cin>>n>>k;
	for(int i = 1;i<n;i++){
		int p;
		cin>>p;
		tree[p].push_back(i+1);
	}
	for(int i = 1;i<=n;i++)cin>>arr[i];
	dfs(1,k);
	cout<<ans<<'\n';
	init();
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
