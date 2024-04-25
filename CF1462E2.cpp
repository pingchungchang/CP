#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll mod = 1e9+7;
const ll mxn = 4e5+10;
ll fac[mxn];
const ll pw(ll a,ll b){
	ll now = 1;
	while(b != 0){
		if(b&1)now = now*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return now;
}
ll inverse(ll k){
	return pw(k,mod-2);
}
ll C(ll a,ll b){
	if(b>a)return 0LL;
	else return fac[a]*inverse(fac[a-b])%mod*inverse(fac[b])%mod;
}
ll bit[mxn];
ll n,m,k;
void modify(ll p,ll v){
	for(;p<=n;p += p&-p)bit[p] += v;
	return;
}
ll getval(ll s,ll e){
	ll re = 0;
	for(;e>0;e -= e&-e)re += bit[e];
	s--;
	for(;s>0;s -= s&-s)re -= bit[s];
	return re;
}
void solve(){
	cin>>n>>m>>k;
	fill(bit,bit+n+1,0LL);
	ll ans = 0;
	ll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i = n-1;i>=0;i--){
		ll total = getval(arr[i],(arr[i]+k>n?n:arr[i]+k));
		ans += C(total,m-1);
		if(ans>=mod)ans -= mod;
		modify(arr[i],1);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	fac[0] = fac[1] = 1;
	for(ll i = 2;i<mxn;i++){
		fac[i] = fac[i-1]*i%mod;
	}
	int t;
	cin>>t;
	while(t--)solve();
}
/*
1
3 2 3
1 1 1
*/
