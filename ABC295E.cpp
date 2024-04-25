#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const ll mod = 998244353;
const ll mxn = 2022;
ll fac[mxn],ifac[mxn];
ll cnt,arr[mxn];

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
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll C(ll a,ll b){
	if(a<b)return 0ll;
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++){
		fac[i] = fac[i-1]*i%mod;
		ifac[i] = inv(fac[i]);
	}
	ll sum = 0;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++)if(!arr[i])cnt++;
	for(int i = 1;i<=m;i++){
		ll r = n-k+1;
		for(int j = 0;j<n;j++)if(arr[j]>=i)r--;
		r = max(0ll,r);
		for(int j = r;j<=cnt;j++){
			sum = mad(sum,C(cnt,j)*pw(m-i+1,j)%mod*pw(i-1,cnt-j)%mod);
		}
	}
	cout<<sum*inv(pw(m,cnt))%mod;
}
