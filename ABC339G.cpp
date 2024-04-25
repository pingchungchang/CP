#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ls segtree[now].pl
#define rs segtree[now].pr
#define mid ((l+r)>>1)
#define int ll

const ll mxn = 2e5+10;
const ll inf = 1e9+10;

ll N,Q;
ll arr[mxn];

struct node{
	int pl,pr;
	ll sum;
	node(){
		pl = pr = sum = 0;
	}
};

const int S = 210;
node segtree[mxn*S];
int ppp = 0;
int newnode(int cp = 0){
	ppp++;
	if(ppp>=mxn*S)exit(0);
	segtree[ppp] = segtree[cp];
	return ppp;
}

int modify(int now,int l,int r,int p){
	now = newnode(now);
	if(l == r){
		segtree[now].sum += p;
		return now;
	}
	if(mid>=p)ls = modify(ls,l,mid,p);
	else rs = modify(rs,mid+1,r,p);
	segtree[now].sum = segtree[ls].sum+segtree[rs].sum;
	return now;
}

ll getval(int now,int l,int r,int s,int e){
	if(!now)return 0ll;
	if(l>=s&&e>=r)return segtree[now].sum;
	if(mid>=e)return getval(ls,l,mid,s,e);
	else if(mid<s)return getval(rs,mid+1,r,s,e);
	else return getval(ls,l,mid,s,e)+getval(rs,mid+1,r,s,e);
}

int rt[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++){
		cin>>arr[i];
		rt[i] = modify(rt[i-1],0,inf,arr[i]);
	}
	cin>>Q;
	ll ans = 0;
	while(Q--){
		ll s,e,v;
		cin>>s>>e>>v;
		s ^= ans;
		e ^= ans;
		bool flag = (s<=e&&e<=N&&s>=1);
		if(!flag)exit(0);
		v ^= ans;
		cout<<(ans = (getval(rt[e],0,inf,0,v)-getval(rt[s-1],0,inf,0,v)))<<'\n';
	}
	return 0;
}
