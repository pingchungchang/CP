#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,k,g;
	cin>>n>>k>>g;
	ll l = 0,r = k;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if((mid*g+n-1)/n<(g+1)/2)l = mid;
		else r = mid-1;
	}
	cout<<l*g<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
