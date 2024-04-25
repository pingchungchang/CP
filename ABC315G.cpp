#include <bits/stdc++.h>
using namespace std;

#define ll __int128_t
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

inline pll extgcd(ll a,ll b,ll c){
	pll ta = {1,0},tb={0,1};
	if(a<0)ta.fs = -ta.fs,a = -a;
	if(b<0)tb.fs = -tb.fs,b = -b;
	if(__gcd(a,b) != __gcd(a,__gcd(b,c)))return make_pair(0,0);
	while(a != 1){
		if(a<b){
			swap(a,b);
			swap(ta,tb);
		}
		ll tmp = a/b;
		ta.fs -= tb.fs*tmp;
		ta.sc -= tb.sc*tmp;
		a -= b*tmp;
		swap(a,b);
		swap(ta,tb);
	}
	return make_pair(c*ta.fs,c*ta.sc);
}
inline ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}

ll G;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,a,b,c,x;
	long long in;
	cin>>in;n = in;
	cin>>in;a = in;
	cin>>in;b = in;
	cin>>in;c = in;
	cin>>in;x = in;
	G = b*c/gcd(b,c);
	pll p = {G/b,G/c};
	long long ans = 0;
	for(ll i = 1;i<=n;i++){
		ll tmp = x-a*i;
		if(tmp<=0)break;
		pll coef = extgcd(b,c,tmp);
		if(coef.fs<=0){
			ll v = abs(coef.fs)/p.fs+1;
			coef.fs += v*p.fs;
			coef.sc -= v*p.sc;
		}
		if(coef.sc<=0){
			ll v = abs(coef.sc)/p.sc+1;
			coef.fs += v*p.fs;
			coef.sc -= v*p.sc;
		}
		ll C = min(coef.fs/p.fs,coef.sc/p.sc);
		coef.fs -= C*p.fs;coef.sc -= C*p.sc;
		assert(coef.fs>0&&coef.sc>0);
		if(coef.fs>n||coef.sc>n)continue;
		ll R = min((n-coef.fs)/p.fs+1,(n-coef.sc)/p.sc+1);
		ans += R;
	}
	cout<<ans;
}
