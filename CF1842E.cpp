#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;

namespace SEG{
#define mid ((l+r)>>1)
	pll segtree[mxn*4];
	void modify(int now,int l,int r,int s,int e,int v){
		if(l>=s&&e>=r){
			segtree[now].sc += v;
			return;
		}
		if(mid>=s)modify(now*2+1,l,mid,s,e,v);
		if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
		segtree[now].fs = min(segtree[now*2+1].fs+segtree[now*2+1].sc,segtree[now*2+2].fs+segtree[now*2+2].sc);
		return;
	}
	ll getval(int now,int l,int r,int s,int e){
		if(l>=s&&e>=r){
			return segtree[now].fs+segtree[now].sc;
		}
		if(mid>=e)return getval(now*2+1,l,mid,s,e)+segtree[now].sc;
		else if(mid<s)return getval(now*2+2,mid+1,r,s,e)+segtree[now].sc;
		else return min(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e))+segtree[now].sc;
	}
}

ll n,k,A;
ll S;
vector<pll> req[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>A;
	for(int i = 0;i<=k;i++){
		SEG::modify(0,0,k,i,i,-A*i);
	}
	for(int i = 0;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		b = k-b;
		req[b].push_back({a,c});
		S += c;
	}
	ll dp,pdp = 0;
	for(int i = 0;i<=k;i++){
		for(auto &j:req[i]){
			SEG::modify(0,0,k,0,j.fs,-j.sc);
			//cout<<j.fs<<','<<j.sc<<endl;
		}
		dp = A*i+SEG::getval(0,0,k,0,i);
		dp = min(dp,pdp);
		pdp = dp;
		//cout<<i<<":"<<SEG::getval(0,0,k,0,i)<<' '<<dp<<endl;
		SEG::modify(0,0,k,i,i,dp);
	}
	cout<<dp+S;
}
