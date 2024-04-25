#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
vector<pii> tree[mxn];
map<int,vector<int>> col;
int low = 0;
int n;
int ans[mxn],ans1[mxn];
int dep[mxn];
int par[mxn][20];
deque<int> chain;
bool done = false;


void dfs(int now){
	for(int i = 1;i<20;i++)par[now][i] = par[par[now][i-1]][i-1];
	for(auto nxt:tree[now]){
		if(nxt.fs == par[now][0])continue;
		dep[nxt.fs] = dep[now]+1;
		par[nxt.fs][0] = now;
		dfs(nxt.fs);
	}
	return;
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int d = dep[a]-dep[b];
	for(int i = 19;i>=0;i--){
		if(d&(1<<i))a = par[a][i];
	}
	for(int i = 19;i>=0;i--){
		if(par[a][i] == par[b][i])a = par[a][i],b = par[b][i];
	}
	return a==b?a:par[a][0];
}

bitset<mxn> tag;
multiset<int> st;
unordered_map<int,int> mp;
int mad = 0;

void dfs2(int now,int pid){
	for(auto nxt:tree[now]){
		if(nxt.sc == pid)continue;
		if(tag[nxt.fs])dfs2(nxt.fs,nxt.sc);
	}
	for(auto nxt:tree[now]){
		if(tag[nxt.fs])continue;
		if(nxt.sc == pid)continue;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back({b,i});
		tree[b].push_back({a,i});
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		col[k].push_back(i);
	}
	par[1][0] = 1;
	dfs(1);
	for(auto it = col.rbegin();it != col.rend();it++){
		if(it->sc.size() <=1)continue;
		if(it->sc.size()>2){
			low = max(low,it->fs);
			break;
		}
		int a = it->sc[0],b = it->sc[1];
		int c = lca(a,b);
		for(int i = a;i!=c;i=par[a][0])tag[i] = true;
		for(int i = b;i!=c;i=par[b][0])tag[i] = true;
		mp.clear();mad = 0;
		dfs2(a,0);
		mp.clear();mad = 0;
		dfs2(b,0);
		while(a != c){
			int ta = par[a][0];
			for(auto nxt:tree[ta]){
				if(nxt.fs == a){
					ans[nxt.sc] = ans1[nxt.sc];
				}
			}
			a = ta;
		}
		while(b != t){
			int tb = par[b][0];
			for(auto nxt:tree[tb]){
				if(nxt.fs == b)ans[nxt.sc] = ans1[nxt.sc];
			}
			b = tb;
		}
		break;
	}
	for(int i = 1;i<n;i++)cout<<max(ans[i],low)<<' ';cout<<'\n';
	return 0;
}
