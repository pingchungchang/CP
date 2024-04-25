#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 1e6+10;
const ll mod = 1e9+7;

ll qpow(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}

struct SEG{
#define mid ((l+r)>>1)
#define ls now*2+1
#define rs now*2+2
	ll seg[mxn*4];
	SEG(){
		for(auto &i:seg)i = 1;
	}
	void modify(int now,int l,int r,int s,int e,ll v){
		if(l>=s&&e>=r){
			seg[now] = seg[now]*v%mod;
			return;
		}
		if(mid>=s)modify(ls,l,mid,s,e,v);
		if(mid<e)modify(rs,mid+1,r,s,e,v);
		return;
	}
	ll getval(int now,int l,int r,int p){
		if(l == r)return seg[now];
		if(mid>=p)return getval(ls,l,mid,p)*seg[now]%mod;
		else return getval(rs,mid+1,r,p)*seg[now]%mod;
	}
#undef ls
#undef rs
#undef mid
};

ll N,Q;
int arr[mxn];
int lpf[mxn];
vector<pii> req[mxn];
ll ans[mxn];
vector<ll> pw[mxn];
vector<ll> rpw[mxn];
vector<pii> pre[mxn];
SEG seg;

void add(int p){
	int tmp = arr[p];
	vector<pii> facs;
	while(tmp != 1){
		if(facs.empty()||facs.back().fs != lpf[tmp])facs.push_back(pii(lpf[tmp],1));
		else facs.back().sc++;
		tmp/=lpf[tmp];
	}
	for(auto &i:facs){
		while(pre[i.fs].back().fs<=i.sc){
			auto tmp = pre[i.fs].back();
			pre[i.fs].pop_back();
			seg.modify(0,1,N,pre[i.fs].back().sc+1,tmp.sc,rpw[i.fs][tmp.fs]);
		}
		seg.modify(0,1,N,pre[i.fs].back().sc+1,p,pw[i.fs][i.sc]);
		pre[i.fs].push_back(pii(i.sc,p));
	}
	return;
}

void check(int p){
	for(auto &i:req[p]){
		ans[i.sc] = seg.getval(0,1,N,i.fs);
	}
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
			pw[i].push_back(1);
			while(pw[i].back()<1e6)pw[i].push_back(pw[i].back()*i);
			for(auto &j:pw[i])rpw[i].push_back(qpow(j,mod-2));
			pre[i].push_back(pii(32,0));
		}
	}
	cin>>N>>Q;
	for(int i = 1;i<=N;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<=Q;i++){
		int s,e;
		cin>>s>>e;
		req[e].push_back(pii(s,i));
	}
	for(int i = 1;i<=N;i++){
		add(i);
		check(i);
	}
	for(int i = 1;i<=Q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
