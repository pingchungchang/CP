#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<int> paths[mxn],dag[mxn];
int low[mxn],idx[mxn],cnt,gcnt,gid[mxn],deg[mxn],sz[mxn],dp[mxn];
bitset<mxn> goneto;
int n,m;
vector<int> st;

void tarjan(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	goneto[now] = true;
	for(auto nxt:paths[now]){
		//cout<<now<<' '<<nxt<<":"<<idx[nxt]<<" "<<goneto[nxt]<<endl;
		if(!idx[nxt]){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
		}
		else if(goneto[nxt]){
			low[now] = min(low[now],idx[nxt]);
		}
	}
	if(idx[now] == low[now]){
		gcnt++;
		while(st.back() != now){
			gid[st.back()] = gcnt;
			goneto[st.back()] = false;
			st.pop_back();
		}
		gid[st.back()] = gcnt;
		goneto[st.back()] = false;
		st.pop_back();
	}
	return;
}

void init(){
	st.clear();
	gcnt = cnt = 0;
	for(int i =0 ;i<=n;i++){
		paths[i].clear();
		dag[i].clear();
		sz[i] = dp[i] = deg[i] = idx[i] = low[i] = gid[i] = 0;
		goneto[i] = 0;
	}
}

void solve(){
	init();
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
	}
	for(int i = 1;i<=n;i++){
		if(!idx[i])tarjan(i);
	}
	for(int i = 1;i<=n;i++){
		sz[gid[i]]++;
		for(auto nxt:paths[i]){
			if(gid[nxt]== gid[i])continue;
			dag[gid[nxt]].push_back(gid[i]);
			deg[gid[i]]++;
		}
	}
	queue<int> q;
	for(int i = 1;i<=gcnt;i++){
		if(!deg[i])q.push(i);
	}
	int ans = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		dp[now] += sz[now];
		ans = max(ans,dp[now]);
		for(auto nxt:dag[now]){
			deg[nxt]--;
			dp[nxt] = max(dp[nxt],dp[now]);
			if(!deg[nxt])q.push(nxt);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
