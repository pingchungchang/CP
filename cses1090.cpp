#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	for(ll i =0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll p=0;
	ll ans=0;
	for(ll i = n-1;i>=0;i--){
		if(p ==i){
			ans++;
			break;
		}
		else if(p>i)break;
		if(arr[i]+arr[p]<=x){
			p++;
			ans++;
		}
		else ans++;
	}
	cout<<ans;
}
