#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	map<int,int> mp;
	int n;
	cin>>n;
	int arr[n+1];
	int ans = 0;
	mp[0] = 1;
	arr[0] = 0;
	for(int i = 1;i<=n;i++){
		char c;
		cin>>c;
		arr[i] = c-'0';
		arr[i] += arr[i-1];
		ans += mp[arr[i]-i];
		mp[arr[i]-i]++;
	}
	//for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	cout<<ans<<'\n';
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
/*
pref[r]-pref[l-1] = r-(l-1)->pref[r]-r = pref[l-1]-(l-1)
*/
