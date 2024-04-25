#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
	int n,m;
	cin>>n>>m;
	vector<ll> v(n);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		ll x = 1;
		for(int j = 0;j<k;j++)x*=10;
		v[i] = x;
	}
	ll val = 0;
	for(int i = 0;i<n-1;i++){
		if((v[i+1]-v[i])/v[i]>m){
			val += v[i]*(m+1);
			m = -1;
			break;
		}
		else{
			val += (v[i+1]-v[i]);
			m -= (v[i+1]-v[i])/v[i];
		}
	}
	val += v[n-1]*(m+1);
	cout<<val<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;++i){
		solve();
	}
}
