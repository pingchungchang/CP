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

ll pw(ll a,ll b,ll mod){
	ll re = 1;
	while(b){
		if(b&1){
			re *= a;
			re %= mod;
		}
		a = a*a%mod;
		b>>=1;
	}
	return re;
}
int main(){
	io
	ll q,p;
	cin>>q>>p;
	while(q--){
		ll x,k;
		cin>>x>>k;
		cout<<pw(p-x,k,p)<<'\n';
	}
	return 0;
}

