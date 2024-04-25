#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mxn = 1e5+10;
int main(){
	ll n;
	cin>>n;
	vector<ll> v(mxn,0LL);
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		v[k] += k;
	}
	for(ll i = 2;i<mxn;i++){
		v[i]+= v[i-2];
		v[i] = max(v[i],v[i-1]);
	}
	cout<<v.back();
}

