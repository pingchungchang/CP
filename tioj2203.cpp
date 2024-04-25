#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const ll mod = 1e9+7;
ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
ll inv2 = pw(2,mod-2);
struct mint{
	ll val;
	mint(){val = 0;}
	mint(ll k){val = k;}
	mint operator%(const mint b)const{return val%b.val;}
	mint operator%(const ll k)const {return (*this)%mint(k);}
	mint operator*(const mint b){return val%mod*(b.val%mod)%mod;}
	mint operator+(const mint b){return (val%mod+b.val%mod)%mod;}
	mint operator=(const ll b){val = b;return *this;}
	mint operator*(const ll k){return (*this)*mint(k);}
	mint operator+(const ll k){return (*this)+mint(k);}
	mint operator-(const mint k){return (val-(k.val%mod)+mod)%mod;}
	mint operator-(const ll k){return (*this)-mint(k);}
	mint operator+=(const mint k){val += k.val;return (*this);}
	mint operator+=(const ll k){return (*this)+=mint(k);}
};
ostream& operator<<(ostream &o,const mint k){o<<k.val;return o;}


struct node{
	mint mvv,vv,mv,vtag,mtag,v,m;
	node(){}
};
ostream& operator<<(ostream &o,const node now){
	o<<now.m<<' '<<now.v<<' '<<now.mtag<<' '<<now.vtag<<' '<<now.mv<<' '<<now.vv<<' '<<now.mv;
	return o;
}
const ll mxn = 1e5+10;
node segtree[mxn*4];
ll n,q;

/*
(m1+dm)*(v1+dv)^2 = (m1+md)*(v1*v1+v1*dv*2+dv*dv) = (m1+dm)*((r-l+1)dv*dv)+(mvv1)+2dv(mv)+dm*(vv+2dvv1)
*/
void push(int now,int l,int r){
	auto m = segtree[now].m,dm = segtree[now].mtag,v = segtree[now].v,dv = segtree[now].vtag;
	segtree[now].mvv = segtree[now].mvv+dm*segtree[now].vv+dv*2*segtree[now].mv+dm*dv*2*v+dv*dv*m+dm*dv*dv*(r-l+1);
	segtree[now].mv = segtree[now].mv+dm*v+dv*m+dm*dv*(r-l+1);
	segtree[now].vv = segtree[now].vv+dv*dv*(r-l+1)+dv*2*v;
	segtree[now].v = segtree[now].v+dv*(r-l+1);
	segtree[now].m = segtree[now].m+dm*(r-l+1);
	segtree[now].mtag = segtree[now].vtag = 0;
	if(l == r)return;
	segtree[now*2+1].mtag += dm;
	segtree[now*2+1].vtag += dv;
	segtree[now*2+2].mtag += dm;
	segtree[now*2+2].vtag += dv;
	return;
}
void pull(int now,int l,int r){
	int mid = (l+r)>>1;
	push(now*2+1,l,mid);
	push(now*2+2,mid+1,r);
	segtree[now].mvv = segtree[now*2+1].mvv+segtree[now*2+2].mvv;
	segtree[now].vv = segtree[now*2+1].vv+segtree[now*2+2].vv;
	segtree[now].mv = segtree[now*2+1].mv+segtree[now*2+2].mv;
	segtree[now].v = segtree[now*2+1].v+segtree[now*2+2].v;
	segtree[now].m = segtree[now*2+1].m+segtree[now*2+2].m;
	return;
}
void mmodify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].mtag += v;
		return;
	}
	int mid = (l+r)>>1;
	push(now,l,r);
	if(mid>=s)mmodify(now*2+1,l,mid,s,e,v);
	if(mid<e)mmodify(now*2+2,mid+1,r,s,e,v);
	pull(now,l,r);
	return;
}
void vmodify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].vtag += v;
		return;
	}
	int mid = (l+r)>>1;
	push(now,l,r);
	if(mid>=s)vmodify(now*2+1,l,mid,s,e,v);
	if(mid<e)vmodify(now*2+2,mid+1,r,s,e,v);
	pull(now,l,r);
	return;
}
mint getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		push(now,l,r);
		return segtree[now].mvv;
	}
	int mid = (l+r)>>1;
	push(now,l,r);
	mint re = 0;
	if(mid>=s)re = re+getval(now*2+1,l,mid,s,e);
	if(mid<e)re = re+getval(now*2+2,mid+1,r,s,e);
	return re;
}

void pv(int now,int l,int r){
	cout<<l<<' '<<r<<':'<<segtree[now]<<endl;
	if(l == r)return;
	int mid = (l+r)>>1;
	pv(now*2+1,l,mid);
	pv(now*2+2,mid+1,r);
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		mmodify(0,1,n,i,i,k);
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		vmodify(0,1,n,i,i,k);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int l,r,x;
			cin>>l>>r>>x;
			mmodify(0,1,n,l,r,x);
		}
		else if(t == 2){
			int l,r,x;
			cin>>l>>r>>x;
			vmodify(0,1,n,l,r,x);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<getval(0,1,n,l,r)*inv2<<'\n';
			// pv(0,1,n);
		}
	}
	return 0;
}
