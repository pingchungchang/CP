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
int c = 1;
void solve(){
	ll n;
	cin>>n;
	vector<pll> v(n);
	for(auto &i:v)cin>>i.fs>>i.sc;
	ll sqsum[2]= {0,0};
	ll sum[2] = {0,0};
	for(auto &i:v){
		sqsum[0] += i.fs*i.fs;
		sum[0] += i.fs;
		sqsum[1] += i.sc*i.sc;
		sum[1] += i.sc;
		sqsum[0] %= mod;
		sqsum[1] %= mod;
		if(sum[0]>=mod)sum[0] -= mod;
		if(sum[1]>=mod)sum[1] -= mod;
	}
	
	int q;cin>>q;
	ll total = 0;
	while(q--){
		ll a,b;
		cin>>a>>b;
		ll k1 = a*a%mod*n%mod;k1 = (k1+mod-sum[0]*2*a%mod)%mod;k1 = (k1+sqsum[0])%mod;
		ll k2 = b*b%mod*n%mod;k2 = (k2+mod-sum[1]*2*b%mod)%mod;k2 = (k2+sqsum[1])%mod;
		total += k1+k2;
		total %= mod;
	}
	cout<<"Case #"<<c++<<": ";
	cout<<total<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

