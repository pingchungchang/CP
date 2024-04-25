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
	vector<pair<int,int>> childs;
	int par;
	node(){par = -1;}
};

bool flag;
int n;
vector<int> ans;
vector<node> tree;
void dfs(int now,int p){
	if(tree[now].childs.size()>2){
		flag = false;
		return;
	}
	for(auto nxt:tree[now].childs){
		if(nxt.fs == tree[now].par)continue;
		ans[nxt.sc] = p;
		tree[nxt.fs].par = now;
		dfs(nxt.fs,5-p);
		p = 5-p;
	}
	return;
	
}
void solve(){
	flag = true;
	cin>>n;
	ans = vector<int>(n+1,0);
	tree = vector<node>(n+1,node());
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].childs.push_back(make_pair(b,i+1));
		tree[b].childs.push_back(make_pair(a,i+1));
	}
	dfs(1,2);
	if(flag == false){
		cout<<-1<<'\n';
	}
	else{
		for(int i = 1;i<=n-1;i++)cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

