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
const int mxn = 5050;
vector<int> tree[mxn];
pii dp[mxn];
int n;
pair<int,vector<int>> ans1;
pair<int,vector<int>> ans2;
void dfs(int now,int par){
	dp[now] = {0,-1};
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		int tmp = dp[nxt].fs+1;
		if(tmp>dp[now].fs){
			swap(dp[now].fs,dp[now].sc);
			dp[now].fs = tmp;
		}
		else if(tmp>dp[now].sc)dp[now].sc = tmp;
	}
	return;
}
void dfs2(int now,int par){
	if(ans1.fs>dp[now].fs)ans1 = {dp[now].fs,{now}};
	else if(ans1.fs==dp[now].fs)ans1.sc.push_back(now);
	if(ans2.fs<dp[now].fs)ans2 = {dp[now].fs,{now}};
	else if(ans2.fs== dp[now].fs)ans2.sc.push_back(now);
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		int tmp;
		if(dp[nxt].fs+1 == dp[now].fs)tmp = dp[now].sc;
		else tmp = dp[now].fs;
		tmp++;
		if(tmp>dp[nxt].fs){
			swap(dp[nxt].fs,dp[nxt].sc);
			dp[nxt].fs = tmp;
		}
		else if(tmp>dp[nxt].sc)dp[nxt].sc = tmp;
		dfs2(nxt,now);
	}
	return;
}
int main(){
	io
	cin>>n>>n;
	n++;
	for(int i= 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	ans1 = {INT_MAX,{}};
	ans2 = {0,{}};
	dfs2(1,1);
	sort(_all(ans1.sc));
	sort(_all(ans2.sc));
//	cout<<ans1.fs<<":";
	for(auto &i:ans1.sc)cout<<i<<' ';cout<<'\n';
//	cout<<ans2.fs<<":";
	for(auto &i:ans2.sc)cout<<i<<' ';cout<<'\n';
	return 0;
}

