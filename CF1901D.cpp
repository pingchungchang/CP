#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const ll mxn = 3e5+10;
ll arr[mxn];
int n;
ll pref[mxn],suf[mxn];

inline bool check(ll atk){
	bool re = false;
	for(int i = 1;i<=n;i++){
		if(atk>=max(suf[i+1],pref[i-1]))re = true;
	}
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++){
		pref[i] = max(pref[i-1],arr[i]+(n-i));
	}
	for(int i = n;i>=1;i--){
		suf[i] = max(suf[i+1],arr[i]+i-1);
	}
	/*
	for(int i = 1;i<=n;i++)cout<<pref[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<suf[i]<<' ';cout<<endl;

   */
	ll l = *max_element(arr+1,arr+n+1),r = 2e9;
	while(l != r){
		ll mid = (l+r)>>1;
		if(check(mid))r = mid;
		else l = mid+1;
	}
	cout<<l;
}
