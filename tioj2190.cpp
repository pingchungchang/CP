#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll mod;

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
	a+= b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

void solve(){
	pll p1,p2;
	ll a,b;
	cin>>mod>>a>>b>>p1.fs>>p1.sc>>p2.fs>>p2.sc;
	ll m = mub(p2.sc,p1.sc)*inv(mub(p2.fs,p1.fs))%mod;
	ll k = mub(p1.sc,m*p1.fs%mod);
	ll m2 = m*m%mod;
	ll x = mub(mub(m2,p1.fs),p2.fs);
	cout<<x<<' '<<mad(x*m%mod,k)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
