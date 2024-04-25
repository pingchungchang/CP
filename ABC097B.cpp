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
	ll x;
	cin>>x;
	ll ans = 1;
	for(ll i = 2;i*i<=x;i++){
		ll now = i*i;
		while(now<=x)now *=i;
		now /=i;
		ans = max(now,ans);
	}
	cout<<ans;
}

