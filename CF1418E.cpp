#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 998244353;
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

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll arr[n+1];
	arr[0] = 0;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	sort(arr,arr+n+1);
	ll pref[n+1];
	pref[0] = 0;
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+arr[i];
	while(m--){
		ll a,b;
		cin>>a>>b;
		ll p = lower_bound(arr,arr+n+1,b)-arr;
		ll ans = 0;
		ll big = n+1-p;
		if(big<a){
			cout<<"0\n";
			continue;
		}
		ll able = big-a;
		ans = mad(ans,(pref[n]-pref[p-1])%mod*(big-a)%mod*inv(big)%mod);
		ans = mad(ans,pref[p-1]%mod*(big-a+1)%mod*inv(big+1)%mod);
		cout<<ans<<'\n';
	}
}
