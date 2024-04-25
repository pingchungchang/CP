#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
int n,m;
vector<int> paths[mxn],dag[mxn],st;
int deg[mxn],idx[mxn],low[mxn],cnt,gcnt,gid[mxn],dp[mxn],sz[mxn];
bitset<mxn> vis;
queue<int> q;

void tarjan(int now){
	st.push_back(now);
	vis[now] = true;
	idx[now] = low[now] = ++cnt;
	for(auto nxt:paths[now]){
		if(vis[nxt])low[now] = min(low[now],idx[nxt]);
		else{
			if(!idx[nxt]){
				tarjan(nxt);
				low[now] = min(low[now],low[nxt]);
			}
		}
	}
	if(low[now] == idx[now]){
		gcnt++;
		while(st.back() != now){
			gid[st.back()] = gcnt;
			vis[st.back()] = false;
			st.pop_back();
		}
		gid[st.back()] = gcnt;
		vis[st.back()] = false;
		st.pop_back();
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a++,b++;
		paths[a].push_back(b);
	}
	for(int i = 1;i<=n;i++){
		if(!idx[i])tarjan(i);
	}
	for(int i = 1;i<=n;i++){
		sz[gid[i]]++;
		for(auto nxt:paths[i]){
			if(gid[i] == gid[nxt])continue;
			dag[gid[i]].push_back(gid[nxt]);
			deg[gid[nxt]]++;
		}
	}
	for(int i = 1;i<=gcnt;i++){
		if(!deg[i])q.push(i);
	}
	int ans =0 ;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		ans = max(ans,dp[now] += sz[now]);
		for(auto nxt:dag[now]){
			deg[nxt]--;
			dp[nxt] = max(dp[nxt],dp[now]);
			if(!deg[nxt])q.push(nxt);
		}
	}
	cout<<ans;
}
