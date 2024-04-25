#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int n;
vector<pii> tree[mxn];
pii edges[mxn];
vector<int> dag[mxn];
pii dp[mxn];
int dual[mxn],deg[mxn];
vector<pii> ans;

void dfs(int now,int par){
	dp[now] = {0,0};
	for(auto nxt:tree[now]){
		if(nxt.fs == par)continue;
		dfs(nxt.fs,now);
		if(dp[nxt.fs].fs>dp[nxt.fs].sc){
			dp[now].sc++;
			dual[nxt.sc] = 0;
		}
		else {
			dp[now].fs++;
			dual[nxt.sc] = 1;
		}
	}
	return;
}

void solve(){
	ans.clear();
	for(int i = 0;i<=n;i++){
		deg[i] = 0;
		dp[i] = {0,0};
		dual[i] = 0;
		dag[i].clear();
		tree[i].clear();
		edges[i] = {0,0};
	}
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		edges[i] = {a,b};
		tree[a].push_back({b,i});
		tree[b].push_back({a,i});
	}
	dfs(1,1);
	for(int i = 1;i<=n;i++){
		vector<int> ev,od;
		for(auto nxt:tree[i]){
			if(dual[nxt.sc])od.push_back(nxt.sc);
			else ev.push_back(nxt.sc);
		}
		if(tree[i].size()%2 == 0)swap(od,ev);
		if(!(od.size()>=ev.size()&&od.size()<=ev.size()+1)){
			cout<<"NO\n";
			return;
		}
		od.push_back(0);
		for(int j = 0;j<ev.size();j++){
			dag[od[j]].push_back(ev[j]);
			dag[ev[j]].push_back(od[j+1]);
			deg[ev[j]]++;
			deg[od[j+1]]++;
		}
	}
	cout<<"YES\n";
	queue<int> q;
	for(int i = 1;i<n;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(!now)continue;
		ans.push_back(edges[now]);
		for(auto nxt:dag[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	/*
	for(int i = 1;i<n;i++){
		cout<<edges[i].fs<<" "<<edges[i].sc<<":"<<dual[i]<<'\n';
	}

   */
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
