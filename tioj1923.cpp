#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll

const int mxn = 4e5+10;
const ll inf = (1e16+10);
vector<pii> range[mxn];
ll val[mxn];
pll segtree[mxn*4];

void modify(int now,int l,int r,int s,int e,ll v){
	if(l>=s&&e>=r){
		segtree[now].sc += v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].fs = min(segtree[now*2+1].fs+segtree[now*2+1].sc,segtree[now*2+2].fs+segtree[now*2+2].sc);
	return;
}

int getsmall(int now,int l,int r){
	if(l == r){
		return l;
	}
	int mid = (l+r)>>1;
	if(segtree[now*2+1].fs+segtree[now*2+1].sc<segtree[now*2+2].fs+segtree[now*2+2].sc)return getsmall(now*2+1,l,mid);
	else return getsmall(now*2+2,mid+1,r);
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		int r;
		cin>>val[i]>>r;
		val[i] = val[i];
		int tl = i-r,tr = i+r;
		if(tl<=0){
			range[i].push_back({tl+n,n});
			range[i].push_back({1,tr});
		}
		else if(tr>n){
			range[i].push_back({tl,n});
			range[i].push_back({1,tr-n});
		}
		else range[i].push_back({tl,tr});
		for(auto &j:range[i]){
			modify(0,1,n,j.fs,j.sc,val[i]);
		}
		modify(0,1,n,i,i,-val[i]);
	}
	modify(0,1,n,1,n,-inf);
	vector<int> v;
	for(int i = 1;i<=n;i++){
		int now = getsmall(0,1,n);
		v.push_back(now);
		for(auto &j:range[now]){
			modify(0,1,n,j.fs,j.sc,-val[now]);
		}
		modify(0,1,n,now,now,inf+val[i]);
	}
	reverse(v.begin(),v.end());
	for(auto &i:v)cout<<i<<' ';
	return 0;
}
