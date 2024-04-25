#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 2e5+10;
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

ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
ll N,M;
ll fac[mxn],ifac[mxn];

ll C(ll a,ll b){
	assert(a>=b);
	return fac[a]*ifac[a-b]%mod*ifac[b]%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	ifac[mxn-1] = inv(fac[mxn-1]);
	for(int i = mxn-2;i>=0;i--)ifac[i] = ifac[i+1]*(i+1)%mod;
	cin>>N>>M;
	if(N == 2){
		cout<<0;
		return 0;
	}
	ll ans = 0;
	for(int L = 3;L<=N;L++)ans = mad(ans,C(M,N-1));
	/*
	for(int L = 3;L<=N;L++){
		for(int i = N-L;i<=M-L+1;i++){
			ans = mad(ans,C(i,N-L)*C(M-i-1,L-2)%mod);
		}
	}

   */
	ans = ans*pw(2,N-3)%mod;
	cout<<ans;
}
