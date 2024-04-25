#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
ll f(ll val){
	ll re = 0;
	ll now = 0;
	for(ll i =0;i<v.size();i++){
		now += v[i];
		if(now>val){
			now = v[i];
			re++;
		}
	}
	return re;
}

int main(){
	ll n,k;
	cin>>n>>k;
	ll total =0;
	v =vector<ll>(n);
	for(ll i =0;i<n;i++){
		cin>>v[i];
		total += v[i];
	}
	ll l = 0;
	ll r = total;
	while(r != l){
		ll mid = (l+r)/2;
//		printf("%lld %lld %lld %lld\n",l,mid,r,f(mid));
		if(f(mid)>=k){
			l = mid+1;
		}
		else r = mid;
	}
	cout<<l;
}
