#include <bits/stdc++.h>
using namespace std;


struct node{
	vector<int> childs;
	int par[32];
	int dep;
	node(){
		dep = 0;
		for(int i = 0;i<32;i++)par[i] = 1;
	}
	
};
vector<node> tree;

void dfs(int now){
	for(int i = 1;i<32;i++){
		tree[now].par[i] = tree[tree[now].par[i-1]].par[i-1];
	}
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par[0])continue;
		tree[nxt].dep = tree[now].dep+1;
		tree[nxt].par[0] = now;
		dfs(nxt);
	}
	return;
}

int lca(int a,int b){
	if(a == b)return a;
	if(tree[a].dep>tree[b].dep)swap(a,b);
	if(tree[a].dep != tree[b].dep){
		int diff = tree[b].dep-tree[a].dep;
		for(int i = 31;i>=0;i--){
			if((diff&(1<<i)) != 0)return lca(a,tree[b].par[i]);
		}
	}
	else{
		for(int i = 31;i>=0;i--){
			if(tree[a].par[i] != tree[b].par[i])return lca(tree[a].par[i],tree[b].par[i]);
		}
		return tree[a].par[0];
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	int q;
	cin>>n;
	cin>>q;
	tree = vector<node>(n+1,node());
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		tree[p].childs.push_back(i);
		tree[i].par[0] = p;
	}
	dfs(1);
//	for(int i = 1;i<=n;i++)cout<<i<<' '<<tree[i].dep<<',';
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<lca(a,b)<<endl;
	}
}

