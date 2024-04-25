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
ll n,m;
vector<ll> v;

bool f(ll k){
	ll now = 0;
//	cout<<k<<":";
	for(auto &i:v){
		if(now>i+k)return false;
		else if(now<=i&&((i+k)%m<now||i+k<m))now = i;
//		cout<<now<<',';
	}
//	cout<<'\n';
	return true;
}
int main(){
	io
	cin>>n>>m;
	v = vector<ll>(n);
	for(ll i = 0;i<n;i++)cin>>v[i];
	ll l = 0,r = m-1;
	while(l != r){
		ll mid = (l+r)/2;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l;
}

