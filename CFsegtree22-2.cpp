#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mod = 1e9+7;
struct node{
	ll sum;
	ll tag;
	node(){
		sum = 0;
		tag = 1LL;
	}
};
vector<node> segtree;

void addsum(int now,int l,int r,int p,ll v){
	if(l == r){
		segtree[now].sum = v;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=p)addsum(now*2+1,l,mid,p,v);
	else addsum(now*2+2,mid+1,r,p,v);
	segtree[now].sum = segtree[now*2+1].sum+segtree[now*2+2].sum;
	return;
}
void addtag(int now,int l,int r,int s,int e,ll v){
	if(l>=s&&e>=r){
		segtree[now].tag *= v;
		segtree[now].tag %= mod;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=s)addtag(now*2+1,l,mid,s,e,v);
	if(mid<e)addtag(now*2+2,mid+1,r,s,e,v);
	segtree[now].sum = ((segtree[now*2+1].sum*segtree[now*2+1].tag%mod)+(segtree[now*2+2].sum*segtree[now*2+2].tag%mod))%mod;
	return;
}
void push(int now){
	segtree[now*2+1].tag = segtree[now*2+1].tag*segtree[now].tag%mod;
	segtree[now*2+2].tag = segtree[now*2+2].tag*segtree[now].tag%mod;
	segtree[now].tag = 1;
	segtree[now].sum = ((segtree[now*2+1].sum*segtree[now*2+1].tag)%mod+(segtree[now*2+2].sum*segtree[now*2+2].tag)%mod)%mod;
	return;
}
ll getval(int now,int l,int r,int s,int e){
//	cout<<l<<' '<<r<<' '<<s<<' '<<e<<endl;
	if(l>=s&&e>=r){
		return segtree[now].tag*segtree[now].sum%mod;
	}
	push(now);
	int mid = (l+r)/2;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return (getval(now*2+1,l,mid,s,e)+getval(now*2+2,mid+1,r,s,e))%mod;
}
int main(){
	io
	ll n,q;
	cin>>n>>q;
	segtree = vector<node>(n*4,node());
	for(int i = 0;i<n;i++){
		addsum(0,0,n-1,i,1);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int s,e,v;
			cin>>s>>e>>v;
			addtag(0,0,n-1,s,e-1,v);
		}
		else{
			int s,e;
			cin>>s>>e;
			cout<<getval(0,0,n-1,s,e-1)<<'\n';
		}
	}
}

