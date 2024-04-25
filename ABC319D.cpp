#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,m;
const int mxn = 2e5+10;
ll arr[mxn];

inline ll f(ll tar){
	ll re = 1;
	ll rest = tar;
	for(int i = 1;i<=n;i++){
		if(rest<arr[i]){
			re++;
			rest = tar;
		}
		rest -= arr[i]+1;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll l = *max_element(arr+1,arr+n+1);
	ll r = 1e18;
	while(l != r){
		ll mid = (l+r)>>1;
		if(f(mid)<=m)r = mid;
		else l = mid+1;
	}
	cout<<l;
}
