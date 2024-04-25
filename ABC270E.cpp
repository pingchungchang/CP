#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
const int mxn = 1e5+10;
ll arr[mxn];
ll n,k;

ll calc(ll r){
	ll total = 0;
	for(int i = 1;i<=n;i++){
		total += min(r,arr[i]);
	}
	return total;
}
main(){
	cin>>n>>k;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll l = 0,r = 1e12;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(calc(mid)<=k)l = mid;
		else r = mid-1;
	}
	ll dif = k-calc(l);
	assert(dif>=0);
	for(int i = 1;i<=n;i++)arr[i] = max(0LL,arr[i]-l);
	for(int i = 1;i<=n;i++){
		if(!dif)break;
		if(arr[i]){
			arr[i]--;
			dif--;
		}
	}
	for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';return 0;
}