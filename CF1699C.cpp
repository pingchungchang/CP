#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


vector<ll> bit;
const ll mxn = 1e5+10;
ll fac[mxn];
ll n;
void modify(ll p,ll val){
	for(;p<=n;p += p&-p){
		bit[p] += val;
	}
	return;
}
ll getval(ll s,ll e){
	ll re = 0;
	for(;e>0; e-= e&-e){
		re += bit[e];
	}
	s--;
	for(;s>0; s-= s&-s)re -= bit[s];
	return re;
}
const ll mod = 1e9+7;
void solve(){
	cin>>n;
	bit = vector<ll>(n+1,0LL);
	vector<ll> pos(n);
	for(ll i = 1;i<=n;i++){
		ll k;
		cin>>k;
		pos[k] = i;
		modify(i,1);
	}
	ll ans = 1;
	ll l = pos[0],r = pos[0];
	modify(l,-1);
	for(ll i = 1;i<n;i++){
		if(l<=pos[i]&&r>=pos[i]){
			ans = ans*getval(l,r)%mod;
			modify(l,-1LL);
		}
		else if(l>pos[i]){
			modify(pos[i],-1);
			l = pos[i];
		}
		else if(r<pos[i]){
			modify(pos[i],-1);
			r = pos[i];
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	fac[0] = 1;
	for(ll i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	int t;
	cin>>t;
	while(t--)solve();
}

