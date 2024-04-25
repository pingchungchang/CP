#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n,m;
	cin>>n>>m;
	vector<ll> v(n+1);
	v[0] = 0;
	for(ll i =1;i<=n;i++){
		cin>>v[i];
		v[i]+= v[i-1];
	}
	ll p1 =0,p2 =0;
	ll ans =0;
	while(p1<=n&&p2<=n){
		if(v[p2]-v[p1] == m){
			ans++;
			p1++;
		}
		else if(v[p2]-v[p1]<m){
			p2++;
		}
		else{
			p1++;
		}
	}
	cout<<ans;
}
