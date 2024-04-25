#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
void solve(){
	vector<ll> v(n);
	vector<ll> ask(n);
	ll k;
	ll sum = 0;
	for(ll i = 0;i<n;i++){
		cin>>v[i];
		sum += v[i];
	}
	ll s1=0;
	ll times = 0;
	cin>>k;
	for(ll i = 0;i<n;i++){
		cin>>ask[i];
		times = max(times,(v[i]+ask[i]-1)/v[i]);
		s1 += ask[i];
	}
	ll left = times*sum-s1;
	ll m;
	cin>>m;
	if(left/k>=m){
		cout<<times<<'\n';
		return;
	}
	else{
		times += (k*m-left+sum-1)/sum;
	}
	cout<<times<<'\n';
	return;
	
}
int main(){
	while(cin>>n)solve();
}
