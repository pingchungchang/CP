#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<vector<ll>> dist;
struct node{
	int fa,sz;
	int dep;
	vector<int> childs;
	bool del;
	ll val;
	node(){
		val = INT_MAX;
		del = false;
		dep = 0;
		sz = 0;
		fa = -1;
	}
};

vector<node> tree;
vector<node> centree;
void find_sz(int now,int par){
	tree[now].sz = 1;
	for(auto nxt:tree[now].childs){
		if(nxt == par||tree[nxt].del)continue;
		find_sz(nxt,now);
		tree[now].sz += tree[nxt].sz;
	}
	return;
}
int find_centroid(int now,int par,int tar){
	for(auto nxt:tree[now].childs){
		if(nxt == par||tree[nxt].del)continue;
		if(tree[nxt].sz>tar)return find_centroid(nxt,now,tar);
	}
	return now;
}
void find_dist(int now,int par,int distance,int dep){
	dist[now][dep] = distance;
	for(auto nxt:tree[now].childs){
		if(tree[nxt].del||nxt == par)continue;
		find_dist(nxt,now,distance+1,dep);
	}
	return;
}
int cendfs(int now,int par,int d){
	find_sz(now,now);
	int c = find_centroid(now,now,tree[now].sz/2);
	centree[c].fa = par;
	centree[par].childs.push_back(c);
	tree[c].del = true;
	for(auto nxt:tree[c].childs){
		if(tree[nxt].del)continue;
		find_dist(nxt,c,1,d);
	}
	for(auto nxt:tree[c].childs){
		if(tree[nxt].del)continue;
		cendfs(nxt,c,d+1);
	}
	centree[c].dep = d;
	return c;
}

void update(int now,int p){
	if(now<=0)return;
	centree[now].val = min(centree[now].val,dist[p][centree[now].dep]);
	update(centree[now].fa,p);
	return;
}
ll getval(int now,int p){
	if(now <= 0)return INT_MAX;
	ll returns = dist[p][centree[now].dep]+centree[now].val;
	return min(returns,getval(centree[now].fa,p));
}
void pv(int now,int par){
	cout<<par<<' '<<now<<'\n';
	for(auto nxt:centree[now].childs){
		if(nxt != par)pv(nxt,now);
	}
	return;
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	tree = vector<node>(n+1,node());
	centree = vector<node>(n+1,node());
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].childs.push_back(b);
		tree[b].childs.push_back(a);
	}
	dist = vector<vector<ll>>(n+1,vector<ll>(31,0));
	int root = cendfs(1,0,0);
//	for(int i = 1;i<=n;i++)cout<<dist[i][0]<<',';
//	pv(root,root);
//	for(int i = 1;i<=n;i++)cout<<centree[i].fa<<' '<<centree[i].dep<<',';
//	return 0;
	centree[1].val = 0;
	update(1,1);
//	for(int i = 1;i<=n;i++)cout<<centree[i].val<<' ';cout<<'\n';
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int p;
			cin>>p;
			centree[p].val = 0;
			update(p,p);
		}
		else{
			int p;
			cin>>p;
			cout<<getval(p,p)<<'\n';
		}
	}
}
/*
10 1
10 7
10 6
1 4
7 8
5 1
6 2
7 5
6 3
7 9

2 9
2 8
2 2
2 7
2 6
*/
