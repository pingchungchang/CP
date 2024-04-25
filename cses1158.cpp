#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,m;
	cin>>n>>m;
	ll dp[m+1];
	memset(dp,0,(m+1)*sizeof(ll));
	vector<pair<ll,ll>> books(n);
	for(ll i =0;i<n;i++){
		ll a;
		cin>>a;
		books[i].first = a;
	}
	for(ll i =0;i<n;i++){
		ll b;
		cin>>b;
		books[i].second =b;
	}
	sort(books.begin(),books.end());
	for(ll i =0;i<n;i++){
		for(ll j = m;j>=books[i].first;j--){
			dp[j] = max(dp[j],dp[j-books[i].first]+books[i].second);
		}
	}
	cout<<dp[m];
}
