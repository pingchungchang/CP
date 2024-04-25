#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int mxn = 1e5+10;
ordered_set st[mxn];

int par[mxn],link_top[mxn],dep[mxn],bs[mxn],sz[mxn],idx[mxn];
vector<int> tr[mxn];
int arr[mxn];
int N;
int cnt = 0;

void dfs1(int now){
	sz[now] = 1;
	for(auto nxt:tr[now]){
		par[nxt] = now;
		dep[nxt] = dep[now]+1;
		dfs1(nxt);
		if(!bs[now]||sz[bs[nxt]]<sz[nxt])bs[now] = nxt;
		sz[now] += sz[nxt];
	}
	return;
}
void dfs2(int now,int top){
	link_top[now] = top;
	idx[now] = ++cnt;
	if(bs[now])dfs2(bs[now],top);
	for(auto nxt:tr[now]){
		if(nxt == bs[now])continue;
		dfs2(nxt,nxt);
	}
	return;
}

int getval(int l,int r,int c){
	auto rp = st[c].order_of_key(r+1);
	auto lp = st[c].order_of_key(l);
	return rp-lp;
}

int lca(int a,int b,int c){
	int ta = link_top[a],tb = link_top[b];
	int re = 0;
	while(ta != tb){
		if(dep[ta]<dep[tb]){
			swap(ta,tb);
			swap(a,b);
		}
		re += getval(idx[ta],idx[a],c);
		a = par[ta];
		ta = link_top[a];
	}
	if(idx[a]>idx[b])swap(a,b);
	re += getval(idx[a],idx[b],c);
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 2;i<=N;i++){
		int p;
		cin>>p;
		tr[p].push_back(i);
	}
	for(int i = 1;i<=N;i++)cin>>arr[i];
	dfs1(1);
	dfs2(1,1);
	for(int i = 1;i<=N;i++){
		st[arr[i]].insert(idx[i]);
	}
	int q;
	cin>>q;
	while(q--){
		int tp;
		cin>>tp;
		if(tp == 1){
			int a,b,c;
			cin>>a>>b>>c;
			cout<<lca(a,b,c)<<'\n';
		}
		else{
			int a,b;
			cin>>a>>b;
			st[arr[a]].erase(idx[a]);
			arr[a] = b;
			st[arr[a]].insert(idx[a]);
		}
	}
	return 0;
}
