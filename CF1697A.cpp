#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	ll n,m;
	cin>>n>>m;
	ll sum = 0LL;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		sum+=k;
	}
	cout<<max(0LL,sum-m)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

