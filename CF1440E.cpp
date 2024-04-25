#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define mid (ll)((l+r)>>1)
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 2e5+10;
int arr[mxn];

struct node{
	ll sum,sm,tag,big;
	node(){}
};
node segtree[mxn*4];

void pull(int now,int l,int r){
	segtree[now].sm = min(segtree[now*2+1].sm,segtree[now*2+2].sm);
	segtree[now].big = max(segtree[now*2+1].big,segtree[now*2+2].big);
	segtree[now].sum = segtree[now*2+1].sum+segtree[now*2+2].sum;
	return;
}

void push(int now,int l,int r){
	if(segtree[now].tag == 0)return;
	segtree[now*2+1].sm = segtree[now*2+2].sm = segtree[now*2+1].tag = segtree[now*2+2].tag = segtree[now].tag;
	segtree[now*2+1].big = segtree[now*2+2].big = segtree[now].tag;
	segtree[now*2+1].sum = segtree[now].tag*(mid-l+1),segtree[now*2+2].sum = segtree[now].tag*(r-mid);
	segtree[now].tag = 0;
	pull(now,l,r);
	return;
}

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].big = segtree[now].sm = segtree[now].tag = v;
		segtree[now].sum = 1ll*v*(r-l+1);
		return;
	}
	push(now,l,r);
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	pull(now,l,r);
}

ll getsum(int now,int l,int r,int s,int e){
	if(e == 0||e<s)return 0ll;
	if(l>=s&&e>=r)return segtree[now].sum;
	push(now,l,r);
	if(mid>=e)return getsum(now*2+1,l,mid,s,e);
	else if(mid<s)return getsum(now*2+2,mid+1,r,s,e);
	else return getsum(now*2+1,l,mid,s,e)+getsum(now*2+2,mid+1,r,s,e);
}

ll getbound(int now,int l,int r,ll tar){
	if(l == r)return l;
	push(now,l,r);
	if(segtree[now*2+1].sum+segtree[now*2+2].big>tar)return getbound(now*2+1,l,mid,tar);
	else return getbound(now*2+2,mid+1,r,tar-segtree[now*2+1].sum);
}

ll getsmall(int now,int l,int r,ll tar){
	if(l == r)return l;
	push(now,l,r);
	if(segtree[now*2+1].sm<=tar)return getsmall(now*2+1,l,mid,tar);
	else return getsmall(now*2+2,mid+1,r,tar);
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		modify(0,1,n,i,i,arr[i]);
	}
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(t == 1){
			int p = getsmall(0,1,n,y);
			if(p<=x)modify(0,1,n,p,x,y);
		}
		else{
			ll ans = 0;
			int p=x-1,np;
			//for(int j = 1;j<=n;j++)cout<<getsum(0,1,n,j,j)<<' ';cout<<'\n';
			do{
				if(p == n)break;
				p = max(p+1,getsmall(0,1,n,y));
				np = getbound(0,1,n,getsum(0,1,n,1,p-1)+y);
				//cout<<y<<":"<<p<<' '<<np<<'\n';
				if(np<p)break;
				ans += np-p+1;
				y -= getsum(0,1,n,p,np);
				p = np;
			}while(true);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
