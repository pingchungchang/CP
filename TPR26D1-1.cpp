#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
vector<pll> req;
vector<ll> all;
vector<ll> deg;
int main(){
	io
	ll n,m;
	cin>>n>>m;
	req = vector<pll>(m);
	for(ll i = 0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		req[i] = make_pair(a,b);
		all.push_back(a);
		all.push_back(b);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(auto &i:req){
		i.fs  = lower_bound(all.begin(),all.end(),i.fs)-all.begin();
		i.sc = lower_bound(all.begin(),all.end(),i.sc)-all.begin();
	}
	deg = vector<ll>(n,0LL);
	for(auto &i:req){
		deg[i.fs]++;
		deg[i.sc]++;
	}
	ll ans= 0;
	for(auto &i:deg){
		ans += i*200+(n-i)*100;
	}
	cout<<ans;
}

