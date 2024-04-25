#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll l,r,m;
	cin>>l>>r>>m;
	for(ll i = l;i<=r;i++){
		ll mm = i-m%i;
		if(mm<=r-l){
			cout<<i<<' '<<l<<' '<<l+mm;cout<<'\n';
			return;
		}
		mm = i-mm;
		if(mm<=r-l){
			cout<<i<<' '<<l+mm<<' '<<l<<'\n';
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
