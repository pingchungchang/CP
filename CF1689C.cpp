#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


struct node{
	int par;
	vector<int> childs;
	int dep;
	int big_son;
	node(){
		dep = 0;
		par= -1;
		big_son = 0;
	}
};
int ans;
vector<node> tree;
void dfs(int now){
	if(tree[now].childs.size()-(tree[now].par == -1?0:1) ==1){
		ans = max(ans,-tree[now].dep*2);
//		cout<<now<<','<<ans<<';';
		return;
	}
	else if(tree[now].childs.size()-(tree[now].par == -1?0:1) ==0){
		ans = max(ans,-tree[now].dep*2+1);
//		cout<<now<<','<<ans<<'.';
		return;
	}
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par)continue;
		tree[nxt].par = now;
		tree[nxt].dep = tree[now].dep+1;
		dfs(nxt);
	}
	return;
	
}
void solve(){
	int n;
	ans = INT_MIN;
	cin>>n;
	tree = vector<node>(n+1,node());
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].childs.push_back(b);
		tree[b].childs.push_back(a);
	}
	tree[1].dep = 1;
	dfs(1);
	cout<<ans+n<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

