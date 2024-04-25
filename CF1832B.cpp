#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int p = 0;
	ll total = 0;
	for(int i = 0;i<n-k;i++)total += arr[i];
	ll ans = total;
	int pt = 0;
	int r = n-k;
	for(int i = 0;i<k;i++){
		total -= arr[pt]+arr[pt+1];
		total += arr[r++];
		pt += 2;
		ans = max(ans,total);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
