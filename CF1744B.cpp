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
void solve(){
	ll n,q;
	cin>>n>>q;
	pll odd = {0,0},even = {0,0};
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(k&1){
			odd.fs+=k;
			odd.sc++;
		}
		else{
			even.fs+=k;
			even.sc++;
		}
	}
	ll ans = odd.fs+even.fs;
	while(q--){
		int t;
		cin>>t;
		ll k;
		cin>>k;
		if(t == 0){
			ans += k*even.sc;
			if(k&1){
				odd.sc += even.sc;
				even.sc = 0;
			}
		}
		else{
			ans += k*odd.sc;
			if(k&1){
				even.sc += odd.sc;
				odd.sc = 0;
			}
		}
		cout<<ans<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

