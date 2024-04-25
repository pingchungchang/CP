#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 998244353;
const ll mxn = 3e5+10;
ll arr[mxn];
ll n;

inline ll pw(ll a,ll b){
	if(b<0)return pw(a,mod-1+b);
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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll ans = 0;
	ll pref = inv(n);
	for(int i = 1;i<=n;i++){
		ans = mad(ans,pref*arr[i]%mod);
		pref = mad(pref,pref*inv(n)%mod);
	}
	cout<<ans;
}
