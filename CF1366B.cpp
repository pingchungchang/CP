#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,m,x;
	cin>>n>>x>>m;
	pll ran = {x,x};
	while(m--){
		ll l,r;
		cin>>l>>r;
		if(r>=ran.fs&&r<=ran.sc){
			ran.fs = min(l,ran.fs);
			ran.sc = max(ran.sc,r);
		}
		if(l>=ran.fs&&l<=ran.sc){
			ran.fs = min(l,ran.fs);
			ran.sc = max(ran.sc,r);
		}
		if(l<=ran.fs&&ran.sc<=r){
			ran.fs = min(l,ran.fs);
			ran.sc = max(ran.sc,r);
		}
	}
	cout<<ran.sc-ran.fs+1<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
