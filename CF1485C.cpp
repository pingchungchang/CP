#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


void solve(){
	ll ans = 0;
	ll a,b;
	cin>>a>>b;
	for(ll m = 1;m*m<=a;m++){
		ll x = min(b,a/m-1)-m;
		ans += max(0LL,x);
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

