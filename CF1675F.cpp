#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node{
	vector<int> childs;
	int par;
	int tag;
	node(){
		tag = 0;
		par = -1;
	}
};
int n,k,x,y;
vector<node> tree;
ll ans;
void dfs1(int now){
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par)continue;
		tree[nxt].par = now;
		dfs1(nxt);
//		cout<<nxt<<' '<<tree[nxt].tag<<',';
		if(tree[nxt].tag == 1){
			ans--;
			tree[now].tag = 1;
		}
		else if(tree[nxt].tag != 0&&tree[now].tag == 0)tree[now].tag = 2;
	}
	if(now == y)tree[now].tag = 1;
}
void dfs2(int now){
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par)continue;
		if(tree[nxt].tag != 0){
			ans += 2;
			dfs2(nxt);
		}
	}
}
void solve(){
	ans = 0;
	cin>>n>>k;
	tree = vector<node>(n+1,node());
	cin>>x>>y;
	while(k--){
		int s;
		cin>>s;
		tree[s].tag = 2;
	}
	
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].childs.push_back(b);
		tree[b].childs.push_back(a);
	}
	dfs1(x);
	dfs2(x);
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

