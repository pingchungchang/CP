#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;
	cin>>n;
	ll arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	ll v[n/2];
	for(int i = 0;i<n/2;i++)v[i] = arr[i]+arr[n-1-i];
	ll pref[n/2];
	ll suff[n/2];
	sort(v,v+(n/2));
	pref[0] = v[0];
	suff[n/2-1] = v[n/2-1];
	for(int i = 1;i<n/2;i++){
		pref[i] = pref[i-1]+v[i];
	}
	for(int i = n/2-2;i>=0;i--)suff[i] = suff[i+1]+v[i];
	
//	for(auto i:v)cout<<i<<' ';
//	cout<<endl;
//	for(auto i:pref)cout<<i<<' ';
//	cout<<endl;
//	for(auto i:suff)cout<<i<<' ';
//	return 0;
	
	ll ans = 0;
	for(int i = 0;i<n/2;i++){
		ll tmp = 0;
		if(i != 0){
			tmp += v[i]*i-pref[i-1];
		}
		if(i != n/2-1){
			tmp += suff[i+1]-v[i]*(n/2-1-i);
		}
//		cout<<tmp<<' ';
		ans += tmp;
	}
	cout<<ans/2;
}
