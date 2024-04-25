#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	ll ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			ans += upper_bound(arr+j+1,arr+n,m-arr[i]-arr[j])-lower_bound(arr+j+1,arr+n,m-arr[i]-arr[j]);
		}
	}
	cout<<ans;
}

