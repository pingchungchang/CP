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

const ll mxn = 2e5+10;
const ll mod = 1e9+7;

void add(ll&a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return;
}
ll pw(ll a,ll b){
	ll now = 1;
	while(b != 0){
		if(b&1)now *= a;
		a *= a;
		a %= mod;
		now %= mod;
		b>>=1;
	}
	return now;
}
ll p1[mxn],inv1[mxn],p2[mxn],inv2[mxn];
ll n;
ll bit1[mxn],rbit1[mxn];
ll vals1[mxn],rvals1[mxn];

void modify(ll b[],int p,ll v){
	for(;p<mxn;p += p&-p)add(b[p],v);
	return;
}
ll getval(ll b[],int s,int e){
	ll re = 0;
	for(;e>0;e -= e&-e){
		add(re,b[e]);
	}
	s--;
	for(;s>0;s -= s&-s){
		add(re,mod-b[s]);
	}
	return re;
}
int main(){
	io
	p1[0] = inv1[0] = p2[0] = inv2[0] = 1;
	p1[1] = 29,p2[1] = 31;
	inv1[1] = pw(29,mod-2),inv2[1] = pw(31,mod-2);
//	return 0;
	for(int i = 2;i<mxn;i++){
		p1[i] = p1[i-1]*p1[1]%mod;
		p2[i] = p2[i-1]*p2[1]%mod;
		inv1[i] = inv1[i-1]*inv1[1]%mod;
		inv2[i] = inv2[i-1]*inv2[1]%mod;
	}
	ll q;
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i = 1;i<=n;i++){
		vals1[i] = 1LL*(s[i-1]-'a')*p1[i-1]%mod;
		modify(bit1,i,vals1[i]);
		rvals1[i] = 1LL*(s[i-1]-'a')*p1[n-i]%mod;
		modify(rbit1,i,rvals1[i]);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int p;
			char c;
			cin>>p>>c;
			modify(bit1,p,mod-vals1[p]);
			modify(rbit1,p,mod-rvals1[p]);
			vals1[p] = 1LL*(c-'a')*p1[p-1]%mod;
			rvals1[p] = 1LL*(c-'a')*p1[n-p]%mod;
			modify(bit1,p,vals1[p]);
			modify(rbit1,p,rvals1[p]);
		}
		else{
			ll be,en;
			cin>>be>>en;
			ll s1 = getval(bit1,be,en);
			ll s2 = getval(rbit1,be,en);
			s1 = s1*inv1[be-1]%mod;
			s2 = s2*inv1[n-en]%mod;
			if(s1 == s2)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
	
}

