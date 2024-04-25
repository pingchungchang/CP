#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid ((l+r)>>1)

const int mxn = 1e4+10;
pii segtree[mxn*4];
int arr[mxn];
pii tree[mxn];
int n;

void build(int now,int l,int r){
	if(l == r){
		segtree[now] = {arr[l],l};
		return;
	}
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	segtree[now] = min(segtree[now*2+1],segtree[now*2+2]);
	return;
}

pii getsmall(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now];
	}
	if(mid>=e)return getsmall(now*2+1,l,mid,s,e);
	else if(mid<s)return getsmall(now*2+2,mid+1,r,s,e);
	else return min(getsmall(now*2+1,l,mid,s,e),getsmall(now*2+2,mid+1,r,s,e));
}

void maketree(int now,int l,int r){
	tree[now] = {0,0};
	if(l != now)tree[now].fs = getsmall(0,1,n,l,now-1).sc;
	if(r != now)tree[now].sc = getsmall(0,1,n,now+1,r).sc;
	if(tree[now].fs)maketree(tree[now].fs,l,now-1);
	if(tree[now].sc)maketree(tree[now].sc,now+1,r);
	return;
}

void dfs(int now){
	if(!now)return;
	cout<<arr[now]<<' ';
	dfs(tree[now].fs);
	dfs(tree[now].sc);
	return;
}

void solve(){
	if(!n)exit(0);
	for(int i = 1;i<=n;i++)cin>>arr[i];
	build(0,1,n);
	int rt = getsmall(0,1,n,1,n).sc;
	maketree(rt,1,n);
	dfs(rt);
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
