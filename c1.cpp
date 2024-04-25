#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second
#define mid ((ll)(l+r)>>1)

const ll mod = 1e9+7;
const ll mxn = 2e5+10;
ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
ll inv(ll k){
	return pw(k,mod-2);
}

struct node{
	int stag,gtag,ssum,gsum,sg;
	int ss,gg;
	node(){
		ss = gg = stag = gtag = ssum = gsum = sg = 0;
	}
};
node segtree[mxn*4];

void push(ll now,int l,int r){
	node &pl = segtree[now*2+1];
	node &pr = segtree[now*2+2];
	pl.gtag = mad(pl.gtag,segtree[now].gtag);
	pl.stag = mad(pl.stag,segtree[now].stag);
	pr.gtag = mad(pr.gtag,segtree[now].gtag);
	pr.stag = mad(pr.stag,segtree[now].stag);
	segtree[now].stag = segtree[now].gtag = 0;
	segtree[now].ssum = mad(mad(pl.ssum,pr.ssum),mad(pl.stag*(mid-l+1)%mod,pr.stag*(r-mid)%mod));
	segtree[now].gsum = mad(mad(pl.gsum,pr.gsum),mad(pl.gtag*(mid-l+1)%mod,pr.gtag*(r-mid)%mod));
	segtree[now].sg = mad(
			(pl.sg+pl.gsum*pl.stag+pl.ssum*pl.gtag+pl.stag*pl.gtag%mod*(mid-l+1))%mod,
			(pr.sg+pr.gsum*pr.stag+pr.ssum*pr.gtag+pr.stag*pr.gtag%mod*(r-mid))%mod);
	segtree[now].gg = mad(
			(pl.gg+pl.gsum*pl.gtag*2%mod+pl.gtag*pl.gtag%mod*(mid-l+1))%mod,
			(pr.gg+pr.gsum*pr.gtag*2%mod+pr.gtag*pr.gtag%mod*(r-mid))%mod);
	segtree[now].ss = mad(
			(pl.ss+pl.ssum*pl.stag*2%mod+pl.stag*pl.stag%mod*(mid-l+1))%mod,
			(pr.ss+pr.ssum*pr.stag*2%mod+pr.stag*pr.stag%mod*(r-mid))%mod);
	return;
}
void modify(int now,int l,int r,int s,int e,int tp,int v){
	if(l>=s&&e>=r){
		if(!tp)segtree[now].stag = mad(segtree[now].stag,v);
		else segtree[now].gtag = mad(segtree[now].gtag,v);
		//cout<<l<<"::"<<r<<' '<<segtree[now].gtag<<endl;
		return;
	}
	push(now,l,r);
	if(mid>=s)modify(now*2+1,l,mid,s,e,tp,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,tp,v);
	node pl = segtree[now*2+1],pr = segtree[now*2+2];
	segtree[now].ssum = mad(mad(pl.ssum,pr.ssum),mad(pl.stag*(mid-l+1)%mod,pr.stag*(r-mid)%mod));
	segtree[now].gsum = mad(mad(pl.gsum,pr.gsum),mad(pl.gtag*(mid-l+1)%mod,pr.gtag*(r-mid)%mod));
	segtree[now].sg = mad(
			(pl.sg+pl.gsum*pl.stag+pl.ssum*pl.gtag+pl.stag*pl.gtag%mod*(mid-l+1))%mod,
			(pr.sg+pr.gsum*pr.stag+pr.ssum*pr.gtag+pr.stag*pr.gtag%mod*(r-mid))%mod);
	segtree[now].gg = mad(
			(pl.gg+pl.gsum*pl.gtag*2%mod+pl.gtag*pl.gtag%mod*(mid-l+1))%mod,
			(pr.gg+pr.gsum*pr.gtag*2%mod+pr.gtag*pr.gtag%mod*(r-mid))%mod);
	segtree[now].ss = mad(
			(pl.ss+pl.ssum*pl.stag*2%mod+pl.stag*pl.stag%mod*(mid-l+1))%mod,
			(pr.ss+pr.ssum*pr.stag*2%mod+pr.stag*pr.stag%mod*(r-mid))%mod);
	//cout<<l<<","<<r<<":"<<segtree[now].ssum<<','<<segtree[now].gsum<<' '<<mad(mad(pl.gsum,pr.gsum),mad(pl.gtag*(mid-l+1)%mod,pr.gtag*(r-mid)%mod))<<endl;
}

ll calc(){
	ll now = 0;
	return segtree[now].sg*segtree[now].sg%mod*inv(segtree[now].ss)%mod*inv(segtree[now].gg)%mod;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	char c;
	while(cin>>c){
		if(c == '?'){
			cin>>c;
			if(c == 'c')cout<<calc()<<'\n';
			else cout<<(1+mod-calc())%mod<<'\n';
		}
		else{
			bool tp = false;
			if(c == 'g')tp = 1;
			ll l,r,v;
			cin>>l>>r>>v;
			modify(0,0,mxn,l,r,tp,v);
		}
	}
	//cout<<segtree[0].ssum<<' '<<segtree[0].gsum<<endl;
}
