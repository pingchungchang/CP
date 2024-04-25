#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll x;
	cin>>x;
	ll ans = x;
	for(ll i = 1;i<=x;i++){
		ll sum = i*(i+1)/2;
		if(sum<x)continue;
		if(sum == x){
			ans = i;
			break;
		}
		else if(sum>=x+2){
			ans = i;
			break;
		}
		else{
			ans = i+1;
			break;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
