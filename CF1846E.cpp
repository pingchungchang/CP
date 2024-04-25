#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld long double

const ll inf = 2e18;

ll calc(ll a,ll b){
	ll re = 0;
	ll p = 1;
	for(ll i = 0;i<b;i++){
		re += p;
		if((ld)p*a>=inf)return inf;
		p *= a;
	}
	re += p;
	return re;
}

void solve(){
	ll n;
	cin>>n;
	for(ll i = 2;i<64;i++){
		ll l = 2,r = 1e9;
		while(l != r){
			ll mid = (l+r)>>1;
			if(calc(mid,i)<n)l = mid+1;
			else r = mid;
		}
		if(calc(l,i) == n){
			cout<<"YES\n";
			return;
		}
		//cout<<i<<":"<<l<<',';
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
/*
k^2+k+1-n = 0
1+4n-4 = 4n-3
*/
