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
const ll mod = 1e9+7;
const ll mxn = 5e5+10;

void modify(ll p,ll val){
	for(;p<mxn;p += p&-p){
		bit[p]+= val;
		bit[p] %= mod;
	}
	return;
}
ll getval(ll s,ll e){
	ll re = 0;
	for(;e>0;e -= e&-e)re = (re+bit[e])%mod;
	s--;
	for(;s>0;s -= s&-s)re = (re+mod-bit[s])%mod;
	return re;
}
int main(){
	io
	ll n;
	cin>>n;
	bit = vector<ll>(mxn,0LL);
	vector<ll> dp(n+1,0LL);
	vector<ll> v(n+1,0LL);
	for(int i = 1;i<=n;i++){
		cin>>v[i];
	}
	for(int i = 1;i<=n;i++){
		dp[i] =1LL + getval(v[i],v[i]+4);
		dp[i]%= mod;
		modify(v[i]+2,dp[i]);
	}
	ll total = 0;
	for(int i = 1;i<=n;i++)total = (total+dp[i])%mod;
	cout<<total<<'\n';
	
}

