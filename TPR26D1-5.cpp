#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double



struct node{
	int link_top,par,sz,bs,dep;
	vector<int> childs;
	int dp;
	node(){
		link_top = par = sz = bs = dep = dp = 0;
	}
};

vector<node> tree;
int ans;
void dfs1(int now){
	tree[now].sz = 1;
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par)continue;
		tree[nxt].par = now;
		tree[nxt].dep = tree[now].dep+1;
		dfs1(nxt);
		if(tree[now].bs == 0||tree[tree[now].bs].sz<tree[nxt].bs)tree[now].bs = nxt;
		tree[now].sz += tree[nxt].sz;
	}
	return;
}
void dfs2(int now,int top){
	tree[now].link_top = top;
	if(now != top){
		tree[now].dp ^= tree[tree[now].par].dp;
	}
	if(tree[now].bs != 0){
		dfs2(tree[now].bs,top);
	}
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par||nxt == tree[now].bs)continue;
		dfs2(nxt,nxt);
	}
	return;
}
vector<int> chars;
void lca(int a,int b){
	int ta = tree[a].link_top,tb = tree[b].link_top;
	while(ta != tb){
		if(tree[ta].dep<tree[tb].dep){
			swap(ta,tb);
			swap(a,b);
		}
		ans ^= tree[a].dp;
		a = tree[ta].par;
		ta = tree[a].link_top;
	}
	if(tree[a].dep>tree[b].dep)swap(a,b);
	ans ^= (tree[b].dp^tree[a].dp);
	ans ^= (1<<chars[a]);
	return;
}
int main(){
	io
	ll n,q;
	cin>>n>>q;
	chars = vector<int>(n+1,0);
	tree = vector<node>(n+1,node());
	for(int i = 1;i<=n;i++){
		char c;
		cin>>c;
		chars[i] = c-'a';
		tree[i].dp^=(1<<(c-'a'));
	}
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].childs.push_back(b);
		tree[b].childs.push_back(a);
	}
	dfs1(1);
	dfs2(1,1);
	while(q--){
		ans = 0;
		int a,b;
		cin>>a>>b;
		lca(a,b);
		int k = 0;
		while(ans != 0){
			k += (ans&1);
			ans>>=1;
		}
		if(k<2)cout<<"YES\n";
		else cout<<"NO\n";
	}
}

