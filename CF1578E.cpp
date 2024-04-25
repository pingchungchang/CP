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
	ll h,p;
	cin>>h>>p;
	ll n = (1LL<<h)-1;
	ll now = 1;
	ll ans = 0;
	while(now<p&&n>0){
		n -= now;
		ans++;
		now<<=1;
	}
	ans += (n+p-1)/p;
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

