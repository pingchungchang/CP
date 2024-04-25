#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n+1] = {};
	int deg[n+1] = {};
	int dp[n+1] = {};
	bool cycle[n+1] = {};
	vector<int> paths[n+1];
	vector<int> rg[n+1];
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] += i;
		if(arr[i]>=1&&arr[i]<=n)deg[i]++,paths[arr[i]].push_back(i),rg[i].push_back(arr[i]);
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(!deg[i]){
			q.push(i);
			cycle[i] = true;
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt]){
				q.push(nxt);
				cycle[nxt] = true;
			}
		}
	}
	for(int i = 1;i<=n;i++)cycle[i] ^= 1;

	for(int i = 1;i<=n;i++)deg[i] = 0;
	for(int i = 1;i<=n;i++)for(auto &j:rg[i])deg[j]++;
	for(int i = 1;i<=n;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		dp[now]++;
		for(auto nxt:rg[now]){
			dp[nxt] += dp[now];
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}

	int lvl[n+1] = {};
	int now = 1;
	int C = 1;
	do{
		lvl[now] = C++;
		now = arr[now];
	}while(now>=1&&now<=n&&!lvl[now]);
	bool flag = false;
	if(now>=1&&now<=n)flag = true;
	C = 0;
	for(int i = 1;i<=n;i++)if(cycle[i])C++;

	/*
	cout<<C<<' '<<flag<<":\n";
	for(int i = 1;i<=n;i++)cout<<lvl[i];cout<<'\n';
	for(int i = 1;i<=n;i++)cout<<cycle[i];cout<<'\n';
	for(int i = 1;i<=n;i++)cout<<dp[i];cout<<'\n';
   */
	for(int i = 1;i<=n;i++){
		if(!lvl[i]){
			if(!flag)ans += n*2+1;
		}
		else{
			if(!flag)ans += n*2+1-C-dp[i];
			else ans += n*2+1-C;
		}
		//cout<<i<<":"<<lvl[i]<<":"<<ans<<',';
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
