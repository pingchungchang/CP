#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,sse4")
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
#define pll pair<ll,ll>
#define ll long long

const ll mxn = 2e5+10;
const ll mxm = 1e6+10;
const ll inf = 1e12+10;

struct line{
	ll m,b,turn;
	line(ll mm = 0,ll bb = 0,ll tt = 0):m(mm),b(bb),turn(tt){}
	pll operator()(ll x)const{
		return pll(m*x+b,turn);
	}
};

vector<ll> all;

struct SEG{
#define mid ((l+r)>>1)
#define ls now*2+1
#define rs now*2+2
	line seg[mxn*4];
	void modify(int now,int l,int r,line v){
		if(l == r){
			if(v(all[l])<seg[now](all[l]))seg[now] = v;
			return;
		}
		if(seg[now](all[mid])>v(all[mid]))swap(seg[now],v);
		if(v.m<seg[now].m)modify(rs,mid+1,r,v);
		else modify(ls,l,mid,v);
		return;
	}
	pll getval(int now,int l,int r,int p){
		if(l == r)return seg[now](all[p]);
		pll re = seg[now](all[p]);
		if(mid>=p)re = min(re,getval(ls,l,mid,p));
		else re = min(re,getval(rs,mid+1,r,p));
		return re;
	}
	void init(int _n = mxn*4){
		for(int i = 0;i<_n;i++)seg[i].m = seg[i].turn = 0,seg[i].b = inf;
		return;
	}

#undef ls
#undef rs
#undef mid
};

vector<pll> v;
vector<ll> sh;
vector<pll> dp;
ll N;
ll lim;

namespace INIT{
	vector<pii> vv;
	void GO(vector<int> row,vector<int> col){
		all.clear();
		vv.clear();
		v.clear();
		sh.clear();
		dp.clear();
		for(int i = 0;i<row.size();i++){
			int r = row[i],c = col[i];
			vv.push_back(pii(min(r,c),max(r,c)+1));
		}
		sort(vv.begin(),vv.end(),[](pii a,pii b){return a.fs == b.fs?a.sc>b.sc:a.fs<b.fs;});
		int rp = -1;
		v.push_back(pii(0,0));
		for(auto &i:vv){
			if(rp>=i.sc)continue;
			rp = i.sc;
			v.push_back(i);
			all.push_back(i.fs);
			all.push_back(i.sc);
		}
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		N = v.size();
		sh.resize(N);
		dp.resize(N);
		//for(auto &i:v)cout<<i.fs<<' '<<i.sc<<',';cout<<endl;
		for(int i = 0;i+1<N;i++){
			sh[i] = 0;
			if(v[i].sc>=v[i+1].fs)sh[i] = 1ll*(v[i].sc-v[i+1].fs)*(v[i].sc-v[i+1].fs);
		}
		for(auto &i:v){
			i.fs = lower_bound(all.begin(),all.end(),i.fs)-all.begin();
			i.sc = lower_bound(all.begin(),all.end(),i.sc)-all.begin();
		}
		dp[0].fs = dp[0].sc = 0;
		return;
	}
}

SEG seg;
namespace ALIENS{
	pll calc(ll cost){
		seg.init(all.size()*4);
		seg.modify(0,0,all.size()-1,line(-all[v[0].fs]*2,all[v[0].fs]*all[v[0].fs]));
		for(int i = 0;i<N;i++){
			auto re = seg.getval(0,0,all.size()-1,v[i].sc);
			dp[i].sc = re.sc+1;
			dp[i].fs = re.fs+all[v[i].sc]*all[v[i].sc]-cost;
			line tmp;
			if(i+1 == N)break;
			tmp.turn = dp[i].sc,tmp.m = -all[v[i+1].fs]*2;
			tmp.b = dp[i].fs+all[v[i+1].fs]*all[v[i+1].fs]-sh[i];
			seg.modify(0,0,all.size()-1,tmp);
		}
		//cout<<cost<<":";for(auto &i:dp)cout<<i.fs<<' ';cout<<endl;
		return dp[N-1];
	}
	ll GO(){
		ll l = -inf,r = 0;
		while(l != r){
			ll mid = l+(r-l+1)/2;
			auto re = calc(mid);
			if(re.sc<=lim)l = mid;
			else r = mid-1;
		}
		auto re = calc(l);
		//cout<<l<<":"<<re.fs<<','<<re.sc<<endl;
		return re.fs+l*lim;
	}
}

#ifdef PCC
#include "aliens.h"
long long take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c) {
	lim = k;
	INIT::GO(r,c);
	return ALIENS::GO();
}

#else
#include "lib1961.h"
vector<int> r,c;
long long take_photos(int n, int m, int k,int rr[],int cc[]) {
	r.clear();c.clear();
	for(int i = 0;i<n;i++){
		r.push_back(rr[i]);
		c.push_back(cc[i]);
	}
	lim = k;
	INIT::GO(r,c);
	return ALIENS::GO();
}
#endif
