#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	ll l,r;
	cin>>l>>r;
	ll ans = 1;
	for(ll i = 0;i<=20;i++){
		if(i>=r)break;
		ll x = r-i;
		ll j = l;
		while(__gcd(j,x) != 1)j++;
		ans = max(ans,x-j);
	}
	cout<<ans;
}

