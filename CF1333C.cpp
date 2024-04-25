#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll



main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll arr[n+1],pref[n+1];
	ll lim[n+1];
	arr[0] = pref[0] = 0;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		pref[i] = pref[i-1]+arr[i];
	}
	ll ans = 0;
	map<ll,ll> mp;
	mp[0] = 0;
	for(int i = 1;i<=n;i++){
		if(mp.find(pref[i]) == mp.end())lim[i] = 0;
		else lim[i] = mp[pref[i]]+1;
		mp[pref[i]] = i;
	}
	ll l = 0;
	for(int i = 1;i<=n;i++){
		l = max(l,lim[i]);
		ans += i-l;
	}
	cout<<ans;
}
