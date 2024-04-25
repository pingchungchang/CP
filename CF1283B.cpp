#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	ll ans = 0;
	ll tar = n/k;
	ans = tar*k+min(n-tar*k,k/2);
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
