#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll ans = 0;
	for(int i = 1;i<n;i++)ans = max(ans,arr[i]*arr[i-1]);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
