#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll segtree[12000];
pll v[3030];
vector<ll> all;//all y values
ll gv(ll n){
	return upper_bound(all.begin(),all.end(),n)-all.begin()-1;
}
void add(ll pos,ll val,ll now,ll l,ll r){
	if(l == r){
		segtree[now] += val;
		return;
	}
	ll mid = (l+r)/2;
	if(mid>=pos)add(pos,val,now*2+1,l,mid);
	else add(pos,val,now*2+2,mid+1,r);
	segtree[now] = segtree[now*2+1]+segtree[now*2+2];
	return;
}
ll getval(ll s,ll e,ll now,ll l,ll r){
	if(s == l&&e == r)return segtree[now];
	ll mid = (l+r)/2;
	if(mid>=e)return getval(s,e,now*2+1,l,mid);
	else if(mid+1<=s)return getval(s,e,now*2+2,mid+1,r);
	else return getval(s,mid,now*2+1,l,mid)+getval(mid+1,e,now*2+2,mid+1,r);
}
int main(){
	ll start = clock();
	io
	ll n,w,h;
	cin>>n>>h>>w;
	for(ll i = 0;i<n;i++){
		cin>>v[i].fs>>v[i].sc;
		all.push_back(v[i].sc);
	}
	sort(v,v+n);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	memset(segtree,0LL,sizeof(segtree));
	ll p = 0;
	ll ans =0;
	ll k = all.size();
	ll bd[k];
	for(auto &i:v){
		i.sc = gv(i.sc);
	}
	ll pp = 0;
	for(ll i = 0;i<k;i++){
		while(pp != k&&all[pp]-all[i]<=h)pp++;
		bd[i] = pp-1;
	}
	for(ll i = 0;i<n;i++){
		if(p == n)break;
		if(p<i)p = i;
		while(p != n && v[p].fs-v[i].fs<=w){
			add(v[p].sc,1LL,0,0,k-1);
			p++;
		}
		for(ll i = 0;i<k;i++){
			ll tmp = getval(i,bd[i],0,0,k-1);
			ans = max(ans,tmp);
		}
		
		
		add(v[i].sc,-1,0,0,k-1);
	
	
	}
	ll finish = clock();
	cout<<ans<<'\n'<<(finish-start)/(double)CLOCKS_PER_SEC;
}

