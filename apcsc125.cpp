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

struct node{
	int l,r,sz;
	node(){
		l = r = sz = 0;
	}
};
const int mxn =  2e5+10;
node tree[mxn];
int dfs(int now,int w){
	tree[now].sz += w;
	if(tree[now].l == 0){
		return now;
	}
	if(tree[tree[now].l].sz<=tree[tree[now].r].sz){
		return dfs(tree[now].l,w);
	}
	else return dfs(tree[now].r,w);
}
void dfs1(int now){
	if(!tree[now].l)return;
	dfs1(tree[now].l);dfs1(tree[now].r);
	tree[now].sz = tree[tree[now].l].sz+tree[tree[now].r].sz;
	return;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i = n;i<=n*2-1;i++)cin>>tree[i].sz;
	vector<int> req(m);
	for(auto &i:req)cin>>i;
	for(int i = 1;i<n;i++){
		int p,s,t;
		cin>>p>>s>>t;
		tree[p].l = s,tree[p].r = t;
	}
	vector<int> ans(m);
	dfs1(1);
	for(int i = 0;i<m;i++){
		ans[i] = dfs(1,req[i]);
	}
	for(auto &i:ans)cout<<i<<' ';
}

