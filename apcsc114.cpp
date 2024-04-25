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

vector<ll> v;
ll n,m;
ll f(ll k){
	ll cnt = 0;
	ll tmp = -1;
	for(auto &i:v){
		if(tmp<i){
			tmp = i+k;
			cnt++;
		}
	}
	return cnt;
}
int main(){
	io
	cin>>n>>m;
	v = vector<ll>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	sort(_all(v));
	ll l = 0,r = INT_MAX;
	while(l != r){
		ll mid = (l+r)/2;
		if(f(mid)>m)l = mid+1;
		else r = mid;
	}
	cout<<l;
}

