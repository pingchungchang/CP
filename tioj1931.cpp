#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e5+10;
ll arr[mxn];

void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	ll ans = 0;
	if(n&1){
		ll tsum = 0;
		for(int i = 1;i<n;i+=2)tsum += (arr[i]+arr[i-1]-abs(arr[i]-arr[i-1]))*2;
		ans = max(ans,tsum);
		tsum = 0;
		for(int i = 2;i<n;i+=2)tsum += (arr[i]+arr[i-1]-abs(arr[i]-arr[i-1]))*2;
		ans = max(ans,tsum);
	}
	else{
		for(int i = 1;i<n;i+=2)ans += (arr[i]+arr[i-1]-abs(arr[i]-arr[i-1]))*2;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
