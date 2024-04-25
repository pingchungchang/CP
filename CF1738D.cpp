#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<int> graph[mxn];
deque<int> ans;
int sz[mxn],bs[mxn];

void dfs1(int now){
	sz[now] = 1;
	bs[now] = 0;
	for(auto nxt:graph[now]){
		dfs1(nxt);
		if(!bs[now]||sz[bs[now]]<sz[nxt])bs[now] = nxt;
		sz[now] += sz[nxt];
	}
	return;
}

void dfs2(int now){
	ans.push_back(now);
	for(auto nxt:graph[now]){
		if(nxt == bs[now])continue;
		dfs2(nxt);
	}
	if(bs[now])dfs2(bs[now]);
}

void solve(){
	int n;
	cin>>n;
	int arr[n+1];
	int k = 0;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		graph[arr[i]].push_back(i);
		if(arr[i]>i)k++;
	}
	dfs1(0);
	dfs2(0);
	dfs1(n+1);
	dfs2(n+1);
	while(ans.front() == n+1||ans.front() == 0)ans.pop_front();
	while(ans.back() == n+1||ans.back() == 0)ans.pop_back();
	cout<<k<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	for(int i =0;i<=n+1;i++){
		bs[i] = 0;
		graph[i].clear();
	}
	ans.clear();
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
