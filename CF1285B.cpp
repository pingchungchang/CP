#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	ll arr[n+1];
	arr[0] = 0;
	for(int i =1 ;i<=n;i++){
		cin>>arr[i];
		arr[i] += arr[i-1];
	}
	ll small = 0;
	ll ans = arr[1];
	for(int i = 1;i<n;i++){
		ans = max(ans,arr[i]-small);
		small = min(small,arr[i]);
		ans = max(ans,arr[n]-arr[i]);
	}
	if(ans<arr[n])cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
