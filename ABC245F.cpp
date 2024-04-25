#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mxn = 2*1e5+5;
int n,m;
int idx[mxn] = {};
int goneto[mxn] = {};
int gp[mxn] = {};
int low[mxn] = {};
int id = 0;
int gn = 0;
stack<int> st;
vector<vector<int>> paths;

vector<vector<int>> path2;
vector<int> tag;

void tarjan(int now){
	id++;
	idx[now] = id;
	low[now] = id;
	st.push(now);
	goneto[now] = 1;
	for(auto nxt:paths[now]){
		if(idx[nxt] == 0){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
		}
		else if(goneto[nxt] == 1){
			low[now] = min(low[now],idx[nxt]);
		}
		else continue;
	}
	if(low[now] == idx[now]){
		while(st.top() != now){
			gp[st.top()] = gn;
			goneto[st.top()] = 0;
			st.pop();
		}
		gp[st.top()] = gn;
		goneto[st.top()] = 0;
		st.pop();
		gn++;
	}
	return;
}

void dfs(int now){
	tag[now] = 0;
	for(auto nxt:path2[now]){
		if(tag[nxt] == -1)dfs(nxt);
		tag[now] |= tag[nxt];
	}
	return;
}
int main(){
	io
	cin>>n>>m;
	paths = vector<vector<int>>(n);
	memset(gp,-1,sizeof(gp));
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b);
	}
		
	for(int i = 0;i<n;i++){
		if(idx[i] == 0){
			tarjan(i);
		}
	}
	vector<int> gs(gn,0);
	for(int i = 0;i<n;i++){
		gs[gp[i]]++;
	}
	
	path2 = vector<vector<int>>(gn);
	tag = vector<int>(gn,-1);
	for(int i = 0;i<n;i++){
		for(auto nxt:paths[i]){
			if(gp[nxt] == gp[i])continue;
			path2[gp[i]].push_back(gp[nxt]);
		}
	}
	for(int i = 0;i<gn;i++){
		if(gs[i] > 1){
			tag[i] = 1;
		}
	}
	
	for(int i = 0;i<gn;i++){
		if(tag[i] == -1)dfs(i);
	}
	
	int ans = 0;
	for(int i = 0;i<gn;i++){
		ans += tag[i]*gs[i];
	}
	cout<<ans;
}

