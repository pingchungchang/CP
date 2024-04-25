#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define int ll


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 1;i<n;i++)cin>>arr[i];
	arr[0] = 0;
	map<int,int> mp;
	int big = 0;
	for(int i = 1;i<n;i++){
		mp[arr[i]-arr[i-1]]++;
		if(mp[arr[i]-arr[i-1]]>1)big++;
	}
	int pt = 1;
	for(;mp.find(pt) != mp.end();pt++);
	for(int i = 1;i<=n-1;i++){
		int d = arr[i]-arr[i-1];
		if(mp[d]>1)big--;
		mp[d]--;
		if(!mp[d])mp.erase(d);
		mp[pt]++;
		mp[d-pt]++;
		if(mp[pt]>1)big++;
		if(mp[d-pt]>1)big++;
		if(big == 0&&mp.begin()->fs == 1&&mp.rbegin()->fs == n){
			cout<<"YES\n";
			return;
		}
		if(mp[pt]>1)big--;
		if(mp[d-pt]>1)big--;
		mp[pt]--;
		mp[d-pt]--;
		if(!mp[pt])mp.erase(pt);
		if(!mp[d-pt])mp.erase(d-pt);
		mp[d]++;
		if(mp[d]>1)big++;
	}
	if(big == 0&&mp.rbegin()->fs<=n)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
