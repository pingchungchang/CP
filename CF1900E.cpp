#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn = 2e5+10;
vector<int> paths[mxn],dag[mxn];
int idx[mxn],low[mxn],gcnt,cnt,gid[mxn];
int arr[mxn];
int n,m;
pll val[mxn],dp[mxn];
bitset<mxn> vis;
vector<int> st;
int deg[mxn];

inline void init(){
	assert(st.empty());
	for(int i = 0;i<=n;i++){
		paths[i].clear();
		dag[i].clear();
		low[i] = idx[i] = gid[i] = arr[i] = val[i].fs = val[i].sc = dp[i].fs = dp[i].sc = deg[i] = 0;
		vis[i] = 0;
	}
	cnt = gcnt = 0;
}

void tarjan(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(vis[nxt])continue;
		if(!idx[nxt]){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
		}
		else low[now] = min(low[now],idx[nxt]);
	}
	if(low[now] == idx[now]){
		gcnt++;
		while(st.back() != now){
			gid[st.back()] = gcnt;
			vis[st.back()] = true;
			st.pop_back();
		}
		gid[st.back()] = gcnt;
		vis[st.back()] = true;
		st.pop_back();
	}
	return;
}


void solve(){
	init();
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
	}
	for(int i = 1;i<=n;i++)if(!vis[i])tarjan(i);
	for(int i = 1;i<=n;i++){
		val[gid[i]].fs++;
		val[gid[i]].sc -= arr[i];
		for(auto nxt:paths[i]){
			if(gid[nxt] == gid[i])continue;
			dag[gid[i]].push_back(gid[nxt]);
			deg[gid[nxt]]++;
		}
	}
	queue<int> q;
	for(int i = 1;i<=gcnt;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		dp[now].fs += val[now].fs;
		dp[now].sc += val[now].sc;
		for(auto nxt:dag[now]){
			dp[nxt] = max(dp[nxt],dp[now]);
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	pll ans = {0,0};
	for(int i = 1;i<=gcnt;i++){
		ans =  max(ans,dp[i]);
	}
	cout<<ans.fs<<' '<<-ans.sc<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
