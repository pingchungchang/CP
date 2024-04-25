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
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	ll G = arr[1]-arr[0];
	for(int i = 2;i<n;i++)G = __gcd(G,arr[i]-arr[0]);
	if((k-arr[0])%G != 0)cout<<"NO\n";
	else cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
