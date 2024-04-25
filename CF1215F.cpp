#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug cout
#else
#define debug cerr
#endif


#define LOCAL 7122

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 8e5+10;
vector<int> paths[mxn],dag[mxn],rdag[mxn],st;
bitset<mxn> vis;
int idx[mxn],low[mxn],cnt,gcnt,gid[mxn];
int deg[mxn];
int N,M,m,P;
pii range[mxn],dp[mxn];
set<int> ans,gans;
int rev[mxn];

void dfs(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(vis[nxt])continue;
		if(!idx[nxt]){
			dfs(nxt);
			low[now] = min(low[now],low[nxt]);
		}
		else low[now] = min(low[now],idx[nxt]);
	}
	if(idx[now] == low[now]){
		gcnt++;
		while(st.back() != now){
			vis[st.back()] = true;
			gid[st.back()] = gcnt;
			st.pop_back();
		}
		vis[st.back()] = true;
		gid[st.back()] = gcnt;
		st.pop_back();
	}
	return;
}

void TOPO(vector<int> g[],pii dist[]){
	for(int i = 1;i<=gcnt;i++)deg[i] = 0;
	for(int i = 1;i<=gcnt;i++){
		for(auto nxt:g[i])deg[nxt]++;
	}
	queue<int> q;
	for(int i = 1;i<=gcnt;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:g[now]){
			dist[nxt].fs = max(dist[nxt].fs,dist[now].fs);
			dist[nxt].sc = min(dist[nxt].sc,dist[now].sc);
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	return;
}

int num[mxn] = {};
int getans(){
	int re = -1;
	cnt = 0;
	vector<pii> op;
	auto add = [&](int k){if(!num[k])cnt++;num[k]++;};
	auto del = [&](int k){num[k]--;if(!num[k])cnt--;};
	for(int i = 1;i<=gcnt;i++){
		if(dp[i].fs>dp[i].sc)continue;
		op.push_back({dp[i].fs,i});
		op.push_back({dp[i].sc+1,-i});
	}
	sort(op.rbegin(),op.rend());
	for(int i = 1;i<=M;i++){
		while(!op.empty()&&op.back().fs == i){
			int tmp = op.back().sc;
			op.pop_back();
			if(tmp>0)add(min(tmp,rev[tmp]));
			else del(min(-tmp,rev[-tmp]));
		}
		if(cnt+cnt == gcnt)return i;
	}
	return -1;
}

void choose(int now){
	if(vis[now])return;
	gans.insert(now);
	vis[now] = vis[rev[now]] = true;
	for(auto nxt:dag[now]){
		choose(nxt);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>P>>M>>m;
	for(int i = 0;i<N;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a+P].push_back(b);
		paths[b+P].push_back(a);
	}
	for(int i = 0;i<P;i++)cin>>range[i].fs>>range[i].sc,range[i+P] = {1,M};
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b+P);
		paths[b].push_back(a+P);
	}
	for(int i = 0;i<P*2;i++){
		if(!vis[i])dfs(i);
	}
	vis.reset();
	for(int i = 0;i<P;i++){
		if(gid[i] == gid[i+P]){
			cout<<-1;
			return 0;
		}
	}
	assert(gcnt%2 == 0);
	for(int i = 1;i<=gcnt;i++)dp[i] = {1,M};
	for(int i = 0;i<P*2;i++){
		dp[gid[i]].fs = max(dp[gid[i]].fs,range[i].fs);
		dp[gid[i]].sc = min(dp[gid[i]].sc,range[i].sc);
		if(i<P){
			rev[gid[i]] = gid[i+P];
			rev[gid[i+P]] = gid[i];
		}
	}
	for(int i = 0;i<P*2;i++){
		for(auto nxt:paths[i]){
			if(gid[nxt] == gid[i])continue;
			dag[gid[i]].push_back(gid[nxt]);
			rdag[gid[nxt]].push_back(gid[i]);
		}
	}
	TOPO(rdag,dp);
	/*
	debug<<"Finished topo"<<endl;
	for(int i = 0;i<P*2;i++)debug<<gid[i]<<' ';debug<<endl;
	for(int i = 1;i<=gcnt;i++)debug<<dp[i].fs<<','<<dp[i].sc<<' ';debug<<endl;
   */

	int re = getans();
	//debug<<"got ans:"<<re<<endl;
	if(re == -1){
		cout<<-1;
		return 0;
	}
	for(int i = 1;i<=gcnt;i++){
		if(dp[i].fs>dp[i].sc||dp[i].fs>re||dp[i].sc<re){
			int r = rev[i];
			//debug<<i<<":"<<r<<'\n';
			if(dp[r].fs>dp[r].sc||dp[r].fs>re||dp[r].sc<re){
				cout<<-1;
				return 0;
			}
			choose(r);
		}
	}
	//debug<<"gans:";for(auto &i:gans)debug<<i<<',';cout<<'\n';
	for(int i = 1;i<=gcnt;i++){
		if(!vis[i])choose(i);
	}
	for(int i = 0;i<P;i++){
		if(gans.find(gid[i]) != gans.end())ans.insert(i+1);
	}
	cout<<ans.size()<<' '<<re<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	//cout<<"DONE!";return 0;
}
