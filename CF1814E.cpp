#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 2e5+10;

struct node{
	ll val[4];
	node(){}
};

node segtree[mxn*4];
ll arr[mxn];

void modify(int now,int l,int r,int id){
	if(l == r){
		segtree[now].val[0] = 0,segtree[now].val[3] = arr[id];
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=id)modify(now*2+1,l,mid,id);
	else modify(now*2+2,mid+1,r,id);
	memset(segtree[now].val,0,sizeof(segtree[now].val));
	segtree[now].val[0] = max({segtree[now*2+1].val[0]+max(segtree[now*2+2].val[0],segtree[now*2+2].val[2]),
			segtree[now*2+1].val[1]+segtree[now*2+2].val[0]});
	segtree[now].val[1] = max({segtree[now*2+1].val[0]+max(segtree[now*2+2].val[3],segtree[now*2+2].val[1]),
			segtree[now*2+1].val[1]+segtree[now*2+2].val[1]});
	segtree[now].val[2] = max({segtree[now*2+1].val[2]+max(segtree[now*2+2].val[2],segtree[now*2+2].val[0]),
			segtree[now*2+1].val[3]+segtree[now*2+2].val[0]});
	segtree[now].val[3] = max({segtree[now*2+1].val[2]+max(segtree[now*2+2].val[1],segtree[now*2+2].val[3]),
			segtree[now*2+1].val[3]+segtree[now*2+2].val[1]});
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	ll total = 0;
	for(int i = 1;i<n;i++){
		cin>>arr[i];
		total += arr[i];
		modify(0,1,n-1,i);
	}
	int q;
	cin>>q;
	while(q--){
		ll k,x;
		cin>>k>>x;
		total -= arr[k];
		total += x;
		arr[k] = x;
		modify(0,1,n-1,k);
		cout<<2LL*(total-segtree[0].val[0])<<'\n';
	}
	return 0;
}
