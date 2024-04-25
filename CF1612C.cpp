#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

ll n,m;
ll f(ll x){
	ll ans = 0;
	if(x>n){
		ans += n*(n+1)/2;
		x -= n;
		ans += (n-x+n-1)*x/2;
	}
	else{
		ans = x*(x+1)/2;
	}
	return ans;
}
void solve(){
	cin>>n>>m;
	ll l = 0,r = n*2-1;
	while(l != r){
		ll mid = (l+r+1)/2;
		if(f(mid)<m)l = mid;
		else r = mid-1;
	}
	cout<<(l<n*2-1?l+1:l)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

