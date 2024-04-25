#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 4e5+10;
int n;
vector<int> tree[mxn];
pii col[mxn];

namespace TWOSAT{
	vector<int> paths[mxn],dag[mxn],st,ans;
	int cnt = 0,gcnt = 0;
	int low[mxn],idx[mxn],dfn[mxn],deg[mxn],gid[mxn];
	bitset<mxn> vis;
	queue<int> q;
	void init(){
		for(int i = 0;i<=n*2;i++){
			paths[i].clear();dag[i].clear();
			idx[i] = low[i] = deg[i] = gid[i] = dfn[i] = 0;
			vis[i] = false;
		}
		ans.clear();
		cnt = gcnt = 0;
	}
	void add_edge(int a,int b){
		//cout<<setw(2)<<(a<=n?a:n-a)<<' '<<(b<=n?b:n-b)<<'\n';
		paths[a].push_back(b);
	}

	void dfs(int now){
		idx[now] = low[now] = ++cnt;
		st.push_back(now);
		for(auto nxt:paths[now]){
			if(vis[nxt])continue;
			if(idx[nxt])low[now] = min(low[now],idx[nxt]);
			else{
				dfs(nxt);
				low[now] = min(low[now],low[nxt]);
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

	bool GO(){
		/*
		for(int i = 1;i<=n*2;i++)cout<<idx[i]<<' ';cout<<'\n';
		for(int i = 1;i<=n*2;i++)cout<<low[i]<<' ';cout<<'\n';

	   */
		for(int i = 1;i<=n*2;i++)if(!vis[i])dfs(i);
		for(int i = 1;i<=n;i++)if(gid[i] == gid[i+n])return false;
		for(int i = 1;i<=n*2;i++){
			for(auto nxt:paths[i]){
				if(gid[nxt] == gid[i])continue;
				dag[gid[i]].push_back(gid[nxt]);
				deg[gid[nxt]]++;
			}
		}
		for(int i = 1;i<=gcnt;i++)if(!deg[i])q.push(i);
		cnt = 0;
		while(!q.empty()){
			auto now = q.front();
			dfn[now] = ++cnt;
			q.pop();
			for(auto nxt:dag[now]){
				deg[nxt]--;
				if(!deg[nxt])q.push(nxt);
			}
		}
		ans.clear();
		for(int i = 1;i<=n;i++){
			if(dfn[gid[i]]>dfn[gid[i+n]])ans.push_back(i);
		}
		return true;
	}
	void PRINT(){
		assert(ans.size() == n/2);
		for(auto &i:ans)cout<<i<<' ';cout<<'\n';
		return;
	}
}

namespace TREE{
	void dfs(int now,int par){
		for(auto nxt:tree[now]){
			if(nxt == par)continue;
			dfs(nxt,now);
			TWOSAT::add_edge(nxt,now);
			TWOSAT::add_edge(now+n,nxt+n);
		}
		return;
	}
}

void solve(){
	for(int i = 1;i<=n;i++)col[i] = make_pair(0,0),tree[i].clear();
	TWOSAT::init();
	cin>>n;
	n*= 2;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		if(col[k].fs)col[k].sc = i;
		else col[k].fs = i;
	}
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	TREE::dfs(col[1].fs,col[1].fs);
	for(int i = 1;i<=n/2;i++){
		TWOSAT::add_edge(col[i].fs,col[i].sc+n);
		TWOSAT::add_edge(col[i].sc,col[i].fs+n);
		TWOSAT::add_edge(col[i].sc+n,col[i].fs);
		TWOSAT::add_edge(col[i].fs+n,col[i].sc);
	}
	if(TWOSAT::GO()){
		TWOSAT::PRINT();
		return;
	}
	//cout<<"split"<<endl;
	TWOSAT::init();
	TREE::dfs(col[1].sc,col[1].sc);
	for(int i = 1;i<=n/2;i++){
		TWOSAT::add_edge(col[i].fs,col[i].sc+n);
		TWOSAT::add_edge(col[i].sc,col[i].fs+n);
		TWOSAT::add_edge(col[i].sc+n,col[i].fs);
		TWOSAT::add_edge(col[i].fs+n,col[i].sc);
	}
	if(TWOSAT::GO()){
		TWOSAT::PRINT();
		return;
	}
	cout<<"-1\n";
	return;
}

main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
