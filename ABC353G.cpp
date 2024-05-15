#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
const ll inf = 1e18;

struct SEG{
#define mid ((l+r)>>1)
#define ls now*2+1
#define rs now*2+2
	ll seg[mxn*4];
	SEG(){
		fill(seg,seg+mxn*4,-inf);
	}
	void modify(int now,int l,int r,int p,ll v){
		if(l == r){
			seg[now] = max(seg[now],v);
			return;
		}
		if(mid>=p)modify(ls,l,mid,p,v);
		else modify(rs,mid+1,r,p,v);
		seg[now] = max(seg[ls],seg[rs]);
		return;
	}
	ll getval(int now,int l,int r,int s,int e){
		if(l>=s&&e>=r)return seg[now];
		if(mid>=e)return getval(ls,l,mid,s,e);
		else if(mid<s)return getval(rs,mid+1,r,s,e);
		else return max(getval(ls,l,mid,s,e),getval(rs,mid+1,r,s,e));
	}
#undef ls
#undef rs
#undef mid
};

SEG ldp,rdp;
ll N,C,M;
ll ans = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>C>>M;
	ldp.modify(0,1,N,1,C);
	rdp.modify(0,1,N,1,-C);
	for(int i = 0;i<M;i++){
		ll p,v;
		cin>>p>>v;
		auto tmp = max(ldp.getval(0,1,N,1,p)-C*p,rdp.getval(0,1,N,p,N)+C*p)+v;
		ans = max(ans,tmp);
		ldp.modify(0,1,N,p,tmp+C*p);
		rdp.modify(0,1,N,p,tmp-C*p);
	}
	cout<<ans<<'\n';
	return 0;
}
