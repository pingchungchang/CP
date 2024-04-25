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
	int val;
	vector<int> childs;
	node(){
		val = 0;
	}
};
vector<node> tree;
void dfs(int now){
	for(auto nxt:tree[now].childs){
		dfs(nxt);
		tree[now].val += tree[nxt].val;
	}
//	cout<<now<<' '<<tree[now].val<<'\n';
	return;
}
void solve(){
	int n;
	cin>>n;
	tree = vector<node>(n+1,node());
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		tree[p].childs.push_back(i);
	}
	string s;
	cin>>s;
	for(int i = 1;i<=n;i++){
		if(s[i-1] == 'W')tree[i].val = 1;
		else tree[i].val = -1;
	}
	int ans = 0;
	dfs(1);
	for(int i = 1;i<=n;i++){
		if(tree[i].val == 0)ans++;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

/*
4
1 1 3
WBWB
*/
