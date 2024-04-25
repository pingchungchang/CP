#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> v;
ll f(ll n){
	ll now = 0;
	ll re =0;
	for(ll i =0;i<v.size();i++){
		if(now+v[i]>n){
			re++;
			now = v[i];
		}
		else{
			now+= v[i];
		}
	}
	return re+1;
}
int main(){
	ll n,k;
	cin>>n>>k;
	ll total =0;
	ll biggest =0;
	v = vector<ll>(n);
	for(ll i =0;i<n;i++){
		cin>>v[i];
		biggest = max(biggest,v[i]);
		total += v[i];
	}
	ll l = biggest;
	ll r = total;
	while(l !=r){
//		cout<<l<<r<<endl;
		ll mid = (l+r)/2;
		if(f(mid) <=k){
			r = mid;
		}
		else l = mid+1;
	}
	cout<<r;
}
