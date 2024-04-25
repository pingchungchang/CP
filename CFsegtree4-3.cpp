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
	ll cnt[41];
	ll val;
	node(){
		memset(cnt,0LL,sizeof(cnt));
		val = 0;
	}
};
vector<node> segtree;
ll arr[41];
void modify(int now,int l,int r,int p,int v){
	if(l == r){
		memset(segtree[now].cnt,0,sizeof(segtree[now].cnt));
		segtree[now].cnt[v] = 1;
		segtree[now].val = 0;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	ll total = 0;
	segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val;
	for(int i = 1;i<=40;i++){
		segtree[now].val += segtree[now*2+1].cnt[i]*total;
		total += segtree[now*2+2].cnt[i];
		segtree[now].cnt[i] = segtree[now*2+1].cnt[i]+segtree[now*2+2].cnt[i];
	}
	return;
}
ll getval(int now,int l,int r,int s,int e){
//	cout<<l<<' '<<r<<' '<<segtree[now].val<<'\n';
//	cout<<'\n';
	if(s<=l&&e>=r){
		ll re = segtree[now].val;
		ll total = 0;
		for(int i = 1;i<=40;i++){
			re += arr[i]*total;
			arr[i] += segtree[now].cnt[i];
			total += segtree[now].cnt[i];
		}
		return re;
	}
	int mid = (l+r)/2;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else{
		return getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e);
	}
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	segtree = vector<node>(n*4+4,node());
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		modify(0,1,n,i,k);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int s,e;
			cin>>s>>e;
			memset(arr,0,sizeof(arr));
			cout<<getval(0,1,n,s,e)<<'\n';
		}
		else{
			int p,v;
			cin>>p>>v;
			modify(0,1,n,p,v);
		}
	}
	return 0;
}
