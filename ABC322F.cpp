#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll
#define mid ((l+r)>>1)


struct node{
	int pref[2],suf[2],big[2],tag;
	node(){
		pref[0] = pref[1] = suf[0] = suf[1] = big[0] = big[1] = tag = 0;
	}
};
const int mxn = 5e5+10;
node segtree[mxn*4];
string s;

void push(int now,int l,int r){
	if(!segtree[now].tag)return;
	int ls = now*2+1,rs = now*2+2;
	swap(segtree[ls].pref[0],segtree[ls].pref[1]);swap(segtree[rs].pref[0],segtree[rs].pref[1]);
	swap(segtree[ls].suf[0],segtree[ls].suf[1]);swap(segtree[rs].suf[0],segtree[rs].suf[1]);
	swap(segtree[ls].big[0],segtree[ls].big[1]);swap(segtree[rs].big[0],segtree[rs].big[1]);
	segtree[ls].tag ^= segtree[now].tag;
	segtree[rs].tag ^= segtree[now].tag;
	segtree[now].tag = 0;
	return;
}

node pull(node ls,node rs,int l,int m,int r){
	node re;
	re.tag = 0;
	for(int i = 0;i<2;i++){
		re.pref[i] = (ls.pref[i] == m-l+1?rs.pref[i]:0)+ls.pref[i];
		re.suf[i] = (rs.suf[i] == r-m?ls.suf[i]:0)+rs.suf[i];
		re.big[i] = max({ls.big[i],rs.big[i],ls.suf[i]+rs.pref[i],re.pref[i],re.suf[i]});
	}
	return re;
}

void build(int now,int l,int r){
	if(l == r){
		if(s[l] == '0')segtree[now].pref[0] = segtree[now].suf[0] = segtree[now].big[0] = 1;
		else segtree[now].pref[1] = segtree[now].suf[1] = segtree[now].big[1] = 1;
		return;
	}
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	segtree[now] = pull(segtree[now*2+1],segtree[now*2+2],l,mid,r);
}

void modify(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		segtree[now].tag ^= 1;
		swap(segtree[now].pref[0],segtree[now].pref[1]);
		swap(segtree[now].suf[0],segtree[now].suf[1]);
		swap(segtree[now].big[0],segtree[now].big[1]);
		return;
	}
	push(now,l,r);
	if(s<=mid)modify(now*2+1,l,mid,s,e);
	if(mid<e)modify(now*2+2,mid+1,r,s,e);
	segtree[now] = pull(segtree[now*2+1],segtree[now*2+2],l,mid,r);
}

node getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	push(now,l,r);
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else{
		return pull(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e),max(l,s),mid,min(r,e));
	}
}

void dfs(int now,int l,int r){
	cout<<l<<' '<<r<<":";cout<<segtree[now].pref[0]<<' '<<segtree[now].pref[1]<<' '<<segtree[now].suf[0]<<' '<<segtree[now].suf[1]<<' '<<segtree[now].big[0]<<' '<<segtree[now].big[1]<<' '<<segtree[now].tag<<endl;
	if(l == r)return;
	dfs(now*2+1,l,mid);
	dfs(now*2+2,mid+1,r);
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	s = string(n,'0');
	build(0,0,n-1);
	cin>>s;
	for(int i = 0;i<n;i++)if(s[i] == '1')modify(0,0,n-1,i,i);
	while(q--){
		int t,l,r;
		cin>>t>>l>>r;
		l--,r--;
		if(t == 1)modify(0,0,n-1,l,r);
		else cout<<getval(0,0,n-1,l,r).big[1]<<'\n';
	}
}
