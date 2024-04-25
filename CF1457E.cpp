#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	ll arr[n+1],pref[n+1],pref2[n+1];
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	arr[0] = pref[0] = pref2[0] = 0;
	sort(arr+1,arr+n+1);
	for(ll i = 1;i<=n;i++){
		pref[i] = arr[i]+pref[i-1];
		pref2[i] = i*arr[i]+pref2[i-1];
	}
	ll sum = 0,pt = 0;
	ll height[k+1] = {};
	ll ans = -5e18;
	ll tall = 0;
	for(int i = 1;i<=n;i++){
		sum += height[pt]*arr[i];
		height[pt]++;
		tall = max(tall,height[pt]);
		pt++;if(pt>=k+1)pt -= k+1;
		ll tans = sum+(pref2[n]-pref2[i])-i*(pref[n]-pref[i])+(tall-1)*(pref[n]-pref[i]);
		ans = max(ans,tans);
	}
	cout<<ans;
}
