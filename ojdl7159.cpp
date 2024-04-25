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

const ll mod = 8e7+23;
ll pw(ll a,ll b){
	ll re = 1;
	a %= mod;
	while(b != 0){
		if(b&1)re *= a;
		re  %= mod;
		a = a*a%mod;
		b>>=1;
	}
	return re;
}
int main(){
	ll n,m;
	cin>>n>>m;
	ll k = mod;
	string s;
	cout<<pw((pw(2,n)-1+mod)%mod,m);
	return 0;
}

