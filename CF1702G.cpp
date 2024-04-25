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
	int link_top;
	vector<int> childs;
	int par,bs,sz,dep;
	node(){
		bs = -1;
		dep = 0;
		sz = 0;
		par = -1,link_top = -1;
		
	}
};
vector<node> tree;

void dfs1(int now){
	tree[now].sz = 1;
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par)continue;
		tree[nxt].par = now;
		tree[nxt].dep = tree[now].dep+1;
		dfs1(nxt);
		tree[now].sz += tree[nxt].sz;
		if(tree[now].bs == -1||tree[tree[now].bs].sz<tree[nxt].sz)tree[now].bs = nxt;
	}
	return;
}
void dfs2(int now,int top){
	if(now<=0)return;
	tree[now].link_top = top;
	dfs2(tree[now].bs,top);
	for(auto nxt:tree[now].childs){
		if(nxt == tree[now].par||nxt == tree[now].bs)continue;
		dfs2(nxt,nxt);
	}
	return;
}

int maxtop;
int lca(int a,int b){
	int ta = tree[a].link_top,tb = tree[b].link_top;
	while(ta != tb){
//		cout<<a<<' '<<b<<' '<<ta<<' '<<tb<<' '<<'\n';
		if(tree[ta].dep<tree[tb].dep){
			swap(a,b);
			swap(ta,tb);
		}
		a = tree[ta].par;
		ta = tree[a].link_top;
	}
	if(tree[a].dep<tree[b].dep){
		maxtop = b;
		return a;
	}
	else{
		maxtop = a;
		return b;
	}
}
void solve(){
	int k;
	cin>>k;
	vector<pii> v(k);
	for(int i= 0;i<k;i++){
		cin>>v[i].sc;
		v[i].fs = tree[v[i].sc].dep;
	}
	sort(v.rbegin(),v.rend());
	int now = v[0].sc;
	int sec = now;
	int llca = 1;
	maxtop = v[0].sc;
	for(int i = 1;i<k;i++){
		int tmp = lca(now,v[i].sc);
		if(tmp != v[i].sc){
			sec = v[i].sc;
			llca = tmp;
			break;
		}
	}
//	cout<<now<<' '<<sec<<' '<<llca<<' '<<maxtop<<'\n';
	map<int,int> mp;
	while(tree[now].link_top != tree[llca].link_top){
		mp[tree[now].link_top] = now;
		now = tree[tree[now].link_top].par;
	}
	while(tree[sec].link_top != tree[llca].link_top){
		mp[tree[sec].link_top] = sec;
		sec = tree[tree[sec].link_top].par;
	}
	for(auto i:v){
		if(tree[i.sc].link_top == tree[llca].link_top){
			if(tree[i.sc].dep<tree[llca].dep||tree[maxtop].dep<tree[i.sc].dep){
				cout<<"NO\n";
				return;
			}
		}
		else if(mp.count(tree[i.sc].link_top) == 0 || tree[mp[tree[i.sc].link_top]].dep<tree[i.sc].dep){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int n;
	cin>>n;
	tree = vector<node>(n+1,node());
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].childs.push_back(b);
		tree[b].childs.push_back(a);
	}
	dfs1(1);
	dfs2(1,1);
	int q;
	cin>>q;
	while(q--)solve();
}
/*
9
9 2
1 5
4 5
1 9
7 1
8 9
1 3
6 5
1
4
1 2 6 8
*/

