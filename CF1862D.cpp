#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	ll l = 2,r = 2e9;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(mid*(mid-1)/2<=n)l = mid;
		else r = mid-1;
	}
	ll C = l*(l-1)/2;
	assert(C<=n);
	cout<<l+(n-C)<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
