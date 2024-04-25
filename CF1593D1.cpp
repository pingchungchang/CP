#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
const ll mx = 2e6+10;
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	bool same = true;
	for(ll i = 0;i<n;i++){
		cin>>v[i];
		if(i>0&&v[i] != v[i-1])same = false;
	}
	set<ll> gcds;
	for(ll i = 0;i<n;i++){
		for(ll j = i+1;j<n;j++){
			ll diff = abs(v[j]-v[i]);
			for(ll tmp = 1;tmp<=sqrt(diff);tmp++){
				if(diff%tmp == 0){
					gcds.insert(diff/tmp);
					gcds.insert(tmp);
				}
			}
		}
	}
	if(same){
		cout<<-1<<'\n';
		return;
	}
	ll ans = 1;
	for(auto i:gcds){
		if(i == 0)continue;
		bool flag = true;
		ll mod = (v[0]+i*mx)%i;
		for(ll j = 0;j<n;j++){
			if((v[j]+i*mx)%i != mod){
				flag = false;
			}
		}
		if(flag)ans = i;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

