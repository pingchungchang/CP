#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
bitset<mxn> vis;
vector<int> paths[mxn],stk,dag[mxn];
int idx[mxn],low[mxn],cnt,gcnt,gid[mxn],sz[mxn],dp[mxn],deg[mxn];
int arr[mxn];
string s;
int n,st;

void dfs(int now){
	idx[now] = low[now] = ++cnt;
	stk.push_back(now);
	for(auto nxt:paths[now]){
		if(vis[nxt])continue;
		if(!idx[nxt]){
			dfs(nxt);
			low[now] = min(low[now],low[nxt]);
		}
		else low[now] = min(low[now],low[nxt]);
	}
	if(low[now] == idx[now]){
		gcnt++;
		while(stk.back() != now){
			gid[stk.back()] = gcnt;
			vis[stk.back()] = true;
			stk.pop_back();
		}
		gid[stk.back()] = gcnt;
		vis[stk.back()] = true;
		stk.pop_back();
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>st;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	cin>>s;
	s = "#"+s;
	for(int i = 1;i<=n;i++){
		paths[n+1].push_back(i);
		if(s[i] == 'T')paths[i].push_back(n+1);
	}
	for(int i = 1;i<n;i++){
		if(arr[i]>=arr[i+1])paths[i].push_back(i+1);
		if(arr[i+1]>=arr[i])paths[i+1].push_back(i);
	}
	/*
	for(int i = 1;i<=n+1;i++){
		for(auto nxt:paths[i]){
			cout<<i<<' '<<nxt<<endl;
		}
	}cout<<endl;
   */
	for(int i = 1;i<=n+1;i++)if(!vis[i])dfs(i);
	for(int i = 1;i<=n+1;i++){
		if(i != n+1)sz[gid[i]]++;
		for(auto nxt:paths[i]){
			if(gid[nxt] != gid[i]){
				dag[gid[nxt]].push_back(gid[i]);
				deg[gid[i]]++;
			}
		}
	}
	/*
	for(int i = 1;i<=gcnt;i++){
		for(auto nxt:dag[i]){
			cout<<i<<' '<<nxt<<endl;
		}
	}cout<<endl;

   */
	queue<int> q;
	for(int i = 1;i<=gcnt;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		dp[now] += sz[now];
		for(auto nxt:dag[now]){
			dp[nxt] = max(dp[nxt],dp[now]);
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	/*
	for(int i = 1;i<=n+1;i++){
		cout<<gid[i]<<' ';
	}cout<<endl;

   */
	cout<<dp[gid[st]];
}
