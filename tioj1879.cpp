#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e4+10;
vector<pii> paths[mxn];
int low[mxn],idx[mxn],cnt,gcnt,gid[mxn];
vector<int> st;
vector<int> bcc[mxn];

void dfs(int now,int par){
	low[now] = idx[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(nxt.sc == par)continue;
		if(idx[nxt.fs]){
			low[now] = min(low[now],low[nxt.fs]);
		}
		else{
			dfs(nxt.fs,nxt.sc);
			low[now] = min(low[now],low[nxt.fs]);
		}
	}
	if(low[now] == idx[now]){
		gcnt++;
		while(st.back() != now){
			gid[st.back()] = gcnt;
			bcc[gcnt].push_back(st.back());
			st.pop_back();
		}
		gid[st.back()] = gcnt;
		bcc[gcnt].push_back(st.back());
		st.pop_back();
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back({b,i});
		paths[b].push_back({a,i});
	}
	dfs(0,-1);
	vector<pii> v;
	for(int i = 1;i<=gcnt;i++){
		sort(bcc[i].begin(),bcc[i].end());
		v.push_back({bcc[i][0],i});
	}
	sort(v.begin(),v.end());
	for(int i= 0;i<v.size();i++){
		cout<<i+1<<": ";
		for(auto &i:bcc[v[i].sc])cout<<i<<' ';cout<<'\n';
	}
	return 0;
}
