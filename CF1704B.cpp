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
	ll n,x;
	cin>>n>>x;
	vector<ll> v(n);
	for(ll i = 0;i<n;i++)cin>>v[i];
	pll p = make_pair(v[0]-x,v[0]+x);
	ll ans = 0;
	for(ll i = 1;i<n;i++){
		if(p.sc<v[i]-x||p.fs>v[i]+x){
			ans++;
			p = make_pair(v[i]-x,v[i]+x);
		}
		else{
			p.fs = max(p.fs,v[i]-x);
			p.sc = min(p.sc,v[i]+x);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

