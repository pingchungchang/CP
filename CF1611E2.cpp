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
	int dep,par,l,r;
	vector<int> childs;
	node(){
		dep = par = l = r = 0;
	}
};
vector<int> bit;
int idx;
vector<node> tree;
bool cmp(int a,int b){
	return tree[a].dep<tree[b].dep;
}
void dfs(int now){
	tree[now].l = idx++;
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par)continue;
		tree[nxt].par = now;
		tree[nxt].dep = tree[now].dep+1;
		dfs(nxt);
	}
	tree[now].r = idx++;
	return;
}
void modify(int p,int val){
	for(;p<=idx;p+= p&-p)bit[p] += val;
}
int getval(int p){
	int re = 0;
	for(;p>0;p -= p&-p)re+= bit[p];
	return re;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	idx = 1;
	tree = vector<node>(n+1,node());
	vector<int> v(m);
	for(int i = 0;i<m;i++)cin>>v[i];
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].childs.push_back(b);
		tree[b].childs.push_back(a);
	}
	dfs(1);
	sort(_all(v),cmp);
	idx++;
	bit = vector<int>(idx+2,0);
	int ans = 0;
	for(int i = 0;i<m;i++){
		int now = v[i];
		if(getval(tree[now].l))continue;
		int pre = now;
		int k = 0;
		while(k<=tree[now].dep){
			pre = now;
			now = tree[now].par;
			k++;
//			cout<<now<<endl;
		}
		ans++;
		now = pre;
		modify(tree[now].l,1);
		modify(tree[now].r+1,-1);
	}
	for(int i = 2;i<=n;i++){
		if(tree[i].childs.size() == 1&&getval(tree[i].l) == 0){
			cout<<"-1\n";
			return;
		}
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

