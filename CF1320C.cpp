#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 2e5+10;
pll segtree[mxn*4];
int n,m,k;

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].sc+=v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].fs = max(segtree[now*2+1].fs+segtree[now*2+1].sc,segtree[now*2+2].fs+segtree[now*2+2].sc);
	return;
}


main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,k;
	cin>>n>>m>>k;
	vector<pll> atk,def;
	vector<pair<pll,ll>> mon;
	for(int i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		atk.push_back({a,b});
	}
	for(int i = 0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		def.push_back({a,b});
	}
	for(int i = 0;i<k;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		mon.push_back(make_pair(make_pair(a,b),c));
	}
	sort(mon.begin(),mon.end());sort(atk.begin(),atk.end());sort(def.begin(),def.end());
	ll ans = -atk[0].sc-def[0].sc;
	int pt = 0;
	for(int i = 0;i<m;i++)modify(0,0,m-1,i,i,-def[i].sc);
	for(auto &i:atk){
		while(pt<mon.size()&&mon[pt].fs.fs<i.fs){
			auto pos = lower_bound(def.begin(),def.end(),make_pair(mon[pt].fs.sc+1,-1LL))-def.begin();
			if(pos >= m){
				pt++;
				continue;
			}
			modify(0,0,m-1,pos,m-1,mon[pt].sc);
			pt++;
		}
		ans = max(ans,-i.sc+segtree[0].fs+segtree[0].sc);
	}
	cout<<ans;
}
