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
	vector<int> childs;
	ll l,r,dpl,dpr;
	int par;
	node(){
		l = r = dpl = dpr = 0;
		par = -1;
	}
};
vector<node> tree;

void dfs(int now){
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par)continue;
		tree[nxt].par = now;
		dfs(nxt);
		tree[now].dpl += max(tree[nxt].dpl+abs(tree[nxt].l-tree[now].l),tree[nxt].dpr+abs(tree[nxt].r-tree[now].l));
		tree[now].dpr += max(tree[nxt].dpl+abs(tree[nxt].l-tree[now].r),tree[nxt].dpr+abs(tree[nxt].r-tree[now].r));
	}
	return;
}
void solve(){
	int n;
	cin>>n;
	tree = vector<node>(n+1,node());
	for(int i = 1;i<=n;i++){
		cin>>tree[i].l>>tree[i].r;
	}
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].childs.push_back(b);
		tree[b].childs.push_back(a);
	}
	dfs(1);
	cout<<max(tree[1].dpl,tree[1].dpr)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

