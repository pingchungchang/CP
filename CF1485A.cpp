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
	ll n,k;
	cin>>n>>k;
	ll ans = INT_MAX;
	ll add = 0;
	if(k == 1){
		add = 1;
		k++;
	}
	for(ll i = 0;i<32;i++){
		ll tmp = k+i;
		ll now = n;
		ll tans = 0;
		while(now != 0){
			now/=tmp;
			tans++;
		}
		ans = min(ans,tans+add+i);
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

