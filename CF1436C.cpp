#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

#define ll long long
const ll mod = 1e9+7;
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

const ll mxn = 1010;
ll fac[mxn],ifac[mxn];

inline ll C(ll a,ll b){
	if(b>a)return 0LL;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod,ifac[i] = inv(fac[i]);
	int n,x,p;
	cin>>n>>x>>p;
	int l = 0,r = n;
	set<int> big,small;
	while(l<r){
		int mid =(l+r)>>1;
		if(mid<=p)l = mid+1,small.insert(mid);
		else r = mid,big.insert(mid);
	}
	if(big.find(p) != big.end())big.erase(p);
	if(small.find(p) != small.end())small.erase(p);
	//for(auto &i:big)cout<<i<<' ';cout<<endl;
	//for(auto &i:small)cout<<i<<' ';cout<<endl;
	pii cnt = {(int)small.size(),(int)big.size()};
	cout<<fac[n-1-cnt.fs-cnt.sc]*C(x-1,cnt.fs)%mod*C(n-x,cnt.sc)%mod*fac[cnt.fs]%mod*fac[cnt.sc]%mod;
}
