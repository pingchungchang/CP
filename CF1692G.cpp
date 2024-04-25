#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(ll i = 0;i<n;i++)cin>>arr[i];
	ll pref[n];
	pref[0] = 0;
	for(ll i = 1;i<n;i++){
		pref[i] = pref[i-1]+(arr[i-1]/arr[i]<2?1LL:0LL);
	}
	ll ans= 0;
	for(ll i = k;i<n;i++){
		if(pref[i]-pref[i-k] == k)ans++;
	}
//	for(auto i:pref)cout<<i<<' ';cout<<endl;
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

