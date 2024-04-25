#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int main(){
	io
	ll n,x;
	cin>>n>>x;
	vector<pll> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].fs>>v[i].sc;
	}
	ll ans = LONG_LONG_MAX;
	ll total = 0LL;
	ll sm = INT_MAX;
	for(ll i = 0;i<n;i++){
		total += v[i].fs+v[i].sc;
		sm = min(sm,v[i].sc);
		ans = min(ans,total+(x-i-1)*sm);
	}
	cout<<ans;
}

