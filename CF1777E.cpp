#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
vector<pii> paths[mxn];
bitset<mxn> vis,in;
vector<int> st;
int idx[mxn],low[mxn],gid[mxn],cnt,gcnt;
int n,m;

void dfs(int now,int lim){
	st.push_back(now);
	idx[now] = low[now] = ++cnt;
	for(auto nxt:paths[now]){
		if(nxt.sc>lim)continue;
		if(vis[nxt.fs])continue;
		if(idx[nxt.fs])low[now] = min(low[now],idx[nxt.fs]);
		else{
			dfs(nxt.fs,lim);
			low[now] = min(low[now],low[nxt.fs]);
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

inline bool tarjan(int lim){
	cnt = gcnt =0;
	for(int i = 0;i<=n;i++){
		low[i] = idx[i] = gid[i] = vis[i] = in[i] = false;
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i])dfs(i,lim);
	}
	for(int i = 1;i<=n;i++){
		for(auto nxt:paths[i]){
			if(nxt.sc>lim||gid[nxt.fs] == gid[i])continue;
			in[gid[nxt.fs]] = true;
		}
	}
	int C = 0;
	for(int i = 1;i<=gcnt;i++){
		C += !in[i];
	}
	//cout<<lim<<":"<<C<<endl;
	//for(int i = 1;i<=n;i++)cout<<gid[i]<<' ';cout<<endl;
	return C == 1;
}

void solve(){
	for(int i = 0;i<=n;i++){
		paths[i].clear();
	}
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,0});
		paths[b].push_back({a,c});
	}
	int l = 0,r = 1e9;
	while(l != r){
		int mid = (l+r)>>1;
		if(tarjan(mid))r = mid;
		else l = mid+1;
	}
	if(!tarjan(l))cout<<"-1\n";
	else cout<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
