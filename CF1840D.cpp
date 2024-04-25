#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 2e5+10;
ll arr[mxn];
ll n;
bool f(ll k){
	ll s = n-1;
	for(int i = 0;i<n;i++){
		if(arr[0]+k*2<arr[i]){
			s = i;
			break;
		}
	}
	ll e = 0;
	for(int i = n-1;i>=0;i--){
		if(arr[n-1]-arr[i]>k*2){
			e = i;
			break;
		}
	}
	//cout<<k<<":"<<arr[s]<<' '<<arr[e]<<'\n';
	return arr[e]-arr[s]<=k*2;
}

void solve(){
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	//for(int i = 0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;
	ll l = 0,r = 2e9;
	while(l != r){
		ll mid = (l+r)>>1;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
	return;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
