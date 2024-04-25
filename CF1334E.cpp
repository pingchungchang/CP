#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define int ll
#define sc second

const ll mxn = 4e7+10;
bitset<mxn> isp;
vector<int> primes;
vector<pii> pfac;
vector<pii> fac;
ll fact[mxn/100],ifact[mxn/100];
const ll mod = 998244353;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}


main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac.reserve(mxn/100);
	ifact[0] = fact[0] = 1;
	for(int i = 1;i<mxn/100;i++){
		fact[i] = fact[i-1]*i%mod;
		ifact[i] = inv(fact[i]);
	}
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			primes.push_back(i);
			for(int j = i+i;j<mxn;j+=i)isp[j] = true;
		}
	}

	ll G;
	cin>>G;
	fac.push_back({1,0});
	for(auto &i:primes){
		if(i>G)break;
		if(G%i == 0){
			pfac.push_back({i,0});
			while(G%i == 0){
				G/=i;
				pfac.back().sc++;
			}
			int s = fac.size();
			int p = 1;
			for(int j = 0;j<pfac.back().sc;j++){
				p *= i;
				for(int k = 0;k<s;k++)fac.push_back({fac[k].fs*p,i});
			}
		}
	}
	if(G != 1)pfac.push_back({G,1});
	sort(fac.begin(),fac.end());

	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		ll g = __gcd(a,b);
		a/=g,b/=g;
		ll ta = 0,tb = 0;
		vector<int> v1,v2;
		for(auto &i:pfac){
			if(a%i.fs == 0){
				v1.push_back(0);
				while(a%i.fs == 0){
					a/=i.fs;
					ta++;
					v1.back()++;
				}
			}
			if(b%i.fs == 0){
				v2.push_back(0);
				while(b%i.fs == 0){
					b/=i.fs;
					tb++;
					v2.back()++;
				}
			}
		}
		ll tans = fact[ta]*fact[tb]%mod;
		for(auto &i:v1)tans = tans*ifact[i]%mod;
		for(auto &i:v2)tans = tans*ifact[i]%mod;
		cout<<tans<<'\n';
	}
	return 0;
}
