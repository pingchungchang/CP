#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 5e6+10;
const ll inf = 1e18;
pll pref[mxn];
ll all[mxn];
int pt = 0;
ll sum = 0;
ll arr[mxn];
ll n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		sum += arr[i];
	}
	all[pt++] = -inf;
	all[pt++] = 0;
	sum /=n;
	for(int i = 1;i<=n;i++){
		arr[i] = arr[i]-sum;
		arr[i] += arr[i-1];
	}
	sort(arr+1,arr+n+1);
	sum = 0;
	ll total = 0;
	for(int i = 1;i<=n;i++)total += arr[i];
	ll ans = 1e18;
	for(int i = 1;i<=n;i++){
		sum += arr[i];
		ll tsum = arr[i]*i-sum+(total-sum-arr[i]*(n-i));
		ans = min(ans,tsum);
	}
	cout<<ans;
	return 0;
}
