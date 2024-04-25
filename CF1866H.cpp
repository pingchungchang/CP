#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 998244353;
const ll mxn = 2e5+10;
ll fac[mxn];
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
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	fac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	ll ans = 0;
	for(ll C = 0;C<=n;C++){
		if(C>m)continue;
		ll tans = fac[n]*inv(fac[n-C])%mod*fac[C]%mod*mub(pw(C+1,m-C+1),pw(C,m-C+1))%mod;
		//cout<<C<<":"<<tans<<endl;
		ans = mad(ans,tans);
	}
	cout<<ans;
}
