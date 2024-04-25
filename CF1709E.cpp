#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const int mxn = 2e5+10;
struct node{
	vector<int> childs;
	int par;
	int sz;
	int cenpar;
	int val;
	int dp;
	node(){
		dp = val = sz = par = cenpar = 0;
	}
};
bitset<mxn> del;
vector<node> tree;
int ans;

set<int> st;
set<int> st2;
void get_sz(int now,int par,int pre){
	st2.insert(tree[now].val^pre);
	tree[now].sz = 1;
	for(auto nxt:tree[now].childs){
		if(del[nxt]||nxt == par)continue;
		get_sz(nxt,now,pre^tree[now].val);
		tree[now].sz += tree[nxt].sz;
	}
	return;
}
int cendfs(int now,int par){
	now = get_cen(now,tree[now].sz/2);
	st.clear();
	for(auto nxt:tree[now].childs){
		st2.clear();
		get_sz(nxt,now,0);
		for(auto i:st2){
			if(st.find(tree[now].val^i) != st.end()){
				ans++;
			}
		}
	}	
}
int main(){
	ans = 0;
	int n;
	cin>>n;
	tree = vector<node>(n+1,node());
	for(int i = 1;i<=n;I++){
		cin>>tree[i].val;
	}
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].childs.push_back(b);
		tree[b].childs.push_back(a);
	}
	get_sz(1,1);
	int root = cendfs(1,0);
}

