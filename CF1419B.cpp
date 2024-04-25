#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


vector<ll> v;
void solve(){
	ll k;
	cin>>k;
	ll ans = 0;
	for(int i = 0;i<v.size();i++){
		if(k>=v[i])k-= v[i],ans++;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(ll i = 1;i<32;i++){
		ll tmp = (1LL<<i)-1;
		v.push_back(tmp*(tmp+1)/2);
	}
	while(t--)solve();
}
