#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		arr[i] -= i+1;
	}
	ll cur = 1;
	for(int i = 0;i<k;i++){
		auto p = lower_bound(arr,arr+n,cur)-arr;
		cur += p;
	}
	cout<<cur<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
