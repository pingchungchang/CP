#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e6+10;
pll arr[mxn];
ll n,m,k;
ll G = 0;
vector<pll> v;

pll extgcd(ll a,ll b,ll k){
	if(!k)return {0,0};
	pll ta = {1,0},tb = {0,1};
	if(a<0)a = -a,ta.fs = -1;
	if(b<0)b = -b,tb.sc = -1;
	if(__gcd(a,b) != __gcd(a,__gcd(b,k)))return {-1,-1};
	ll tg = __gcd(a,__gcd(b,k));
	assert(tg);
	a/=tg,b/=tg,k/=tg;
	if(a<b){
		swap(a,b);
		swap(ta,tb);
	}
	while(a != 1){
		ll tmp = a/b;
		ta.fs -= tmp*tb.fs;
		ta.sc -= tmp*tb.sc;
		a -= tmp*b;
		swap(a,b);
		swap(ta,tb);
	}
	return make_pair(ta.fs*k,ta.sc*k);
}

ll calc(ll tar){
	ll total = tar+1;
	for(auto &i:v){
		if(tar<i.fs)continue;
		total -= (tar-i.fs)/G+1;
	}
	return total;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 0;i<n;i++){
		ll tmp;
		cin>>tmp;
		arr[tmp].fs = i+1;
	}
	for(int i = 0;i<m;i++){
		ll tmp;
		cin>>tmp;
		arr[tmp].sc = i+1;
	}
	G = n*m/__gcd(n,m);
	for(int i = 1;i<mxn;i++){
		if(!arr[i].fs||!arr[i].sc)continue;
		arr[i].fs--,arr[i].sc--;
		pll gg;
		if(arr[i].fs>arr[i].sc){
			gg = extgcd(-n,m,arr[i].fs-arr[i].sc);
		}
		else gg = extgcd(n,-m,arr[i].sc-arr[i].fs);
		if(gg.fs*n+arr[i].fs == gg.sc*m+arr[i].sc){
			ll l = -1e6,r = 1e6;
			while(l != r){
				ll mid = l+(r-l)/2;
				ll val = mid*G+gg.fs*n+arr[i].fs;
				if(val<max(arr[i].fs,arr[i].sc))l = mid+1;
				else r = mid;
			}
			ll mx = l*G+gg.fs*n+arr[i].fs;
			//cout<<gg.fs<<' '<<gg.sc<<":"<<mx<<endl;
			v.push_back({mx,-1});
		}
	}
	/*
	cout<<ttt.fs<<','<<ttt.sc<<endl<<endl;
	cout<<G<<":"<<endl;
	for(auto &i:v)cout<<i.fs<<' '<<i.sc<<endl;

   */
	ll l = 0,r = 1e18;
	while(l != r){
		ll mid = (l+r)>>1;
		ll C = calc(mid);
		if(C<k)l = mid+1;
		else r= mid;
	}
	cout<<l+1;
}
