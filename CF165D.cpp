#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const int mxn = 1e5+10;
vector<int> paths[mxn];
int bit[mxn],dep[mxn],fa[mxn],bs[mxn],id[mxn],link_top[mxn],sz[mxn];
int cnt = 0;
void modify(int p,int v){
	for(;p<mxn;p += p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	int re = 0;
	for(;e>0;e -= e&-e)re += bit[e];
	s--;
	for(;s>0;s -= s&-s)re -= bit[s];
	return re;
}
void dfs1(int now,int par){
	fa[now] = par;
	for(auto nxt:paths[now]){
		if(nxt == fa[now])continue;
		dep[nxt] = dep[now]+1;
		fa[nxt] = now;
		dfs1(nxt,now);
		if(bs[now] == 0||sz[nxt]>sz[bs[now]])bs[now] = nxt;
	}
	return;
}
void dfs2(int now,int top){
	link_top[now] = top;
//	cout<<now<<' '<<top<<endl;
	id[now] = ++cnt;
	if(bs[now])dfs2(bs[now],top);
	for(auto nxt:paths[now]){
		if(nxt == fa[now]||nxt == bs[now])continue;
		dfs2(nxt,nxt);
	}
	return;
}
int lca(int a,int b){
	int s = a,e= b;
	int ta = link_top[a],tb = link_top[b];
	int re = 0;
	while(ta != tb){
//		cout<<a<<' '<<b<<' '<<ta<<' '<<tb<<endl;
		if(dep[ta]<dep[tb]){
			swap(ta,tb);
			swap(a,b);
		}
		re += getval(id[ta],id[a]);
		a = fa[ta];
		ta = link_top[a];
	}
	if(a == b){
		if(re)return -1;
		else return dep[s]+dep[e]-dep[a]*2; 
	}
	if(id[a]>id[b])swap(a,b);
	re += getval(id[a]+1,id[b]);
	if(re)return -1;
	else return dep[s]+dep[e]-dep[a]*2;
}
int main(){
	io
	int n;
	cin>>n;
	pii edges[n-1];
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		edges[i] = {a,b};
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	dfs1(1,1);
	dfs2(1,1);
//	for(int i = 1;i<=n;i++)cout<<link_top[i]<<' ';return 0;
	for(auto &i:edges){
		if(dep[i.fs]<dep[i.sc])swap(i.fs,i.sc);
	}
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int k;
			cin>>k;
			k--;
			modify(id[edges[k].fs],-1);
		}
		else if(t == 2){
			int k;
			cin>>k;
			k--;
			modify(id[edges[k].fs],1);
		}
		else{
			int s,e;
			cin>>s>>e;
			cout<<lca(s,e)<<'\n';
		}
	}
	return 0;
}

