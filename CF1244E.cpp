#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e5+10;
ll arr[mxn];
ll pref[mxn];
ll n;
ll K;

ll f(ll tar){
	ll re = 1e18;
	for(ll i = 1;i<=n;i++){
		ll tsum = 1LL*arr[i]*i-pref[i];
		auto pos = upper_bound(arr+1,arr+n+1,arr[i]+tar)-arr-1;
		tsum += pref[n]-pref[pos]-1LL*(arr[i]+tar)*(n-pos);
		re = min(re,tsum);
	}
	for(ll i = 1;i<=n;i++){
		ll tsum = pref[n]-pref[i-1]-1LL*(n-i+1)*arr[i];
		auto pos = upper_bound(arr+1,arr+n+1,arr[i]-tar)-arr-1;
		tsum += 1LL*pos*(arr[i]-tar)-pref[pos];
		//cout<<tar<<' '<<i<<' '<<tsum<<' '<<pos<<' '<<arr[pos]<<' '<<arr[i]-tar<<endl;
		re = min(re,tsum);
	}
	//cout<<tar<<":"<<re<<endl;
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>K;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+arr[i];
	ll l = 0,r = 1e9+10;
	while(l != r){
		ll mid = (l+r)>>1;
		if(f(mid)>K)l = mid+1;
		else r= mid;
	}
	cout<<l;
}
