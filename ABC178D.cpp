#include <bits/stdc++.h>
using namespace std;


#define ll long long

const ll mod = 1e9+7;
ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

const int mxn = 4044;
ll fac[mxn],ifac[mxn];

ll C(ll a,ll b){
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	fac[0] = 1;
	for(int i = 1;i<mxn;i++){
		fac[i] = fac[i-1]*i%mod;
	}
	ifac[mxn-1] = pw(fac[mxn-1],mod-2);
	for(int i = mxn-2;i>=0;i--){
		ifac[i] = ifac[i+1]*(i+1)%mod;
	}
	int n;
	cin>>n;
	ll ans = 0;
	for(int i = 1;i*3<=n;i++){
		ll rest = n-i*3;
		ll tans = C(rest+i-1,rest);
		ans = mad(ans,tans);
	}
	cout<<ans;
}
