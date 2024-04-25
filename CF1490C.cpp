#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<ll> v;

void solve(){
	ll n;
	cin>>n;
	for(ll i = 1;i*i*i<n;i++){
		auto pos = lower_bound(v.begin(),v.end(),n-i*i*i)-v.begin();
		if(v[pos]+i*i*i == n){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(ll i = 1;i<1e4+10;i++)v.push_back(i*i*i);
	int t;cin>>t;
	while(t--)solve();
}
