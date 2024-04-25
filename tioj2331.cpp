#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int n;
ll m;
int arr[mxn];

inline ll check(ll tar){
	ll re = 0;
	ll pt = 0;
	for(int i = 0;i<n;i++){
		ll l = 0,r = i;
		while(l != r){
			ll mid = (l+r+1)>>1;
			if(arr[i]+arr[mid]<=tar)l = mid;
			else r = mid-1;
		}
		if(arr[l]+arr[i]<=tar)re += l+1;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	m = 1ll*n*(n+1)/2-m+1;
	ll l = -3e9,r = 3e9;
	while(l != r){
		ll mid = l+(r-l)/2;
		if(check(mid)>=m)r = mid;
		else l = mid+1;
	}
	if(abs(l)&1)cout<<l<<'\n'<<2;
	else cout<<l/2<<'\n'<<1;
}
