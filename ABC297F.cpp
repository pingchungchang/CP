#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 1e6+10;
const ll mod = 998244353;
ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
ll inv(ll k){
	return pw(k,mod-2);
}

ll fac[mxn];
ll ifac[mxn];

ll C(ll a,ll b){
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}
ll mub(ll a,ll b){
	a = a+mod-b;
	if(a>=mod)a -= mod;
	return a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = fac[1] = 1;
	for(int i = 2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	for(int i = 0;i<mxn;i++)ifac[i] = pw(fac[i],mod-2);
	for(int i = 0;i<mxn;i++)assert(fac[i]*ifac[i]%mod == 1);
	ll h,w,k;
	cin>>h>>w>>k;
	ll total = 0,cnt = 0;
	if(k == 1){
		cout<<1;
		return 0;
	}
	for(ll i = 2;i<=h;i++){
		for(ll j = 2;j<=w;j++){
			if(i*j<k)continue;
			ll num = mub(C(i*j-2,k-2)*2%mod,(k>=4?C(i*j-4,k-4):0));
			if(i*j-4>=k-3)num = mad(num,4LL*(i-2)*(j-2)%mod*C(i*j-4,k-3));
			if(i>=2&&j>=2)
			total = mad(total,num*i%mod*j%mod);
			cnt = mad(cnt,num);
		}
	}
	for(ll j = 2;j<=w;j++){
		if(j<k)continue;
		ll num = h*(w-j+1)%mod*C(j-2,k-2)%mod;
		total = mad(total,num*j%mod);
		cnt = mad(cnt,num);
	}
	for(ll j = 2;j<=h;j++){
		if(j<k)continue;
		ll num = w*(h-j+1)%mod*C(j-2,k-2)%mod;
		total = mad(total,num*j%mod);
		cnt = mad(cnt,num);
	}
	cout<<total*inv(cnt)%mod;
}

/*
seperate x,y
choose x:choose k from (1*w,2*w,3*w,4*w),expected (max-min)
*/
