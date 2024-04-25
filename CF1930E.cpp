#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mod = 998244353;
const ll mxn = 1e6+10;
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
inline ll inv(ll k){return pw(k,mod-2);}
inline ll mad(ll a,ll b){a += b;return a>=mod?a-mod:a;}
inline ll mub(ll a,ll b){return mad(a,mod-b);}
inline ll C(ll a,ll b){return a<b?0:fac[a]*ifac[b]%mod*ifac[a-b]%mod;}

ll ans[mxn];
ll N;

void solve(){
	cin>>N;
	for(int k = 1;k<=(N-1)/2;k++){
		ans[k] = 1;
		for(int j = k*2;j<N;j+=k*2){
			ans[k] = mad(ans[k],C(N,j));
			ll NN = N-j+k*2-2;
			ans[k] = mub(ans[k],C(NN+1,k*2-1));
		}
	}
	for(int i = 1;i<=(N-1)/2;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	ifac[mxn-1] = inv(fac[mxn-1]);
	for(int i = mxn-2;i>=0;i--)ifac[i] = ifac[i+1]*(i+1)%mod;
	assert(fac[330]*ifac[330]%mod==1);
	int t;cin>>t;
	while(t--)solve();
}
