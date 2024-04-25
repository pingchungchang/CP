#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
vector<int> paths[mxn],dag[mxn];
int n,m,gcnt,cnt;
int idx[mxn],low[mxn],gid[mxn],val[mxn],deg[mxn];
bitset<mxn> vis;
vector<int> st;

void tarjan(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(vis[nxt])continue;
		if(!idx[nxt]){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
		}
		else{
			low[now] = min(low[now],idx[nxt]);
		}
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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i])tarjan(i);
	}

	for(int i = 1;i<=n;i++){
		for(auto &j:paths[i]){
			if(gid[i] == gid[j])continue;
			deg[gid[j]]++;
			dag[gid[i]].push_back(gid[j]);
		}
	}
	queue<int> q;
	for(int i = 1;i<=gcnt;i++){
		if(!deg[i])q.push(i);
	}
	cnt = 0;
	while(!q.empty()){
		auto now = q.front();
		val[now] = ++cnt;
		q.pop();
		for(auto nxt:dag[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	assert(cnt == gcnt);
	cout<<cnt<<'\n';
	for(int i = 1;i<=n;i++)cout<<val[gid[i]]<<' ';
	return 0;
}
