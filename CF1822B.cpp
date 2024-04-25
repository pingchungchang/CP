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
	sort(arr,arr+n);
	cout<<max(arr[0]*arr[1],arr[n-1]*arr[n-2])<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
