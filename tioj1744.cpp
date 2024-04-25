#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 5e5+10;
vector<int> paths[mxn],st;
int low[mxn],idx[mxn],cnt,val[mxn],gcnt,gid[mxn];
bitset<mxn> bar,able;
int n,m;
int S,P;

namespace DAG{
	vector<int> paths[mxn];
	int val[mxn];
	int deg[mxn];
	int dp[mxn];
	bitset<mxn> bar;
}

void dfs(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(gid[nxt])continue;
		if(idx[nxt])low[now] = min(low[now],idx[nxt]);
		else{
			dfs(nxt);
			low[now] = min(low[now],low[nxt]);
		}
	}
	if(idx[now] == low[now]){
		gcnt++;
		while(st.back() != now){
			gid[st.back()] = gcnt;
			st.pop_back();
		}
		gid[st.back()] = gcnt;
		st.pop_back();
	}
	return;
}

queue<int> q;
void TOPO(){
	for(int i = 1;i<=gcnt;i++){
		if(!DAG::deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(DAG::bar[now])DAG::dp[now] += DAG::val[now];
		for(auto nxt:DAG::paths[now]){
			DAG::deg[nxt]--;
			if(DAG::bar[now]){
				DAG::bar[nxt] = true;
			}
			DAG::dp[nxt] = max(DAG::dp[now],DAG::dp[nxt]);
			if(!DAG::deg[nxt])q.push(nxt);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++)cin>>val[i];
	cin>>S>>P;
	for(int i =0;i<P;i++){
		int k;
		cin>>k;
		bar[k] = true;
	}
	for(int i = 1;i<=n;i++){
		if(!idx[i])dfs(i);
	}
	for(int i = 1;i<=n;i++){
		DAG::val[gid[i]] += val[i];
		if(bar[i])DAG::bar[gid[i]] = true;
		for(auto nxt:paths[i]){
			if(gid[nxt] == gid[i])continue;
			DAG::paths[gid[i]].push_back(gid[nxt]);
			DAG::deg[gid[nxt]]++;
		}
	}
	/*
	for(int i = 1;i<=n;i++)cout<<gid[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<bar[i]<<' ';cout<<endl;
	for(int i = 1;i<=gcnt;i++)cout<<DAG::bar[i]<<' ';cout<<endl;
	for(int i = 1;i<=gcnt;i++)cout<<DAG::val[i]<<' ';cout<<endl;

   */
	TOPO();
	cout<<DAG::dp[gid[S]];
}
