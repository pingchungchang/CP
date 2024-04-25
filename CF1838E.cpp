#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mod = 1e9+7;
const ll mxn = 2e5+10;
ll fac[mxn],ifac[mxn];

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

inline ll C(ll a,ll b){
	assert(a>=b);
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll tmp;
	for(int i= 0;i<n;i++){
		cin>>tmp;
	}
	ll ans = pw(k,m);
	tmp = 1;
	for(int i = 0;i<n;i++){
		ans = mub(ans,tmp*ifac[i]%mod*pw(k-1,m-i)%mod);
		tmp = tmp*(m-i)%mod;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++){
		fac[i] = fac[i-1]*i%mod;
	}
	ifac[mxn-1] = inv(fac[mxn-1]);
	for(int i = mxn-2;i>=1;i--)ifac[i] = ifac[i+1]*(i+1)%mod;
	for(int i = 0;i<mxn;i++)assert(fac[i]*ifac[i]%mod == 1);
	int t;cin>>t;
	while(t--)solve();
}
