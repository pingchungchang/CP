#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll y,x;
	cin>>y>>x;
	ll k = max(y,x);
	ll ans = 1+k*(k-1);
	ll fac = 1;
	if(k%2==0){
		fac = -1;
	}
	else fac = 1;
	if(y>x){
		ans -=(y-x)*fac;
	}
	else if(x>y){
		ans += (x-y)*fac;
	}
	cout<<ans<<'\n';
}
int main(){
	ll t;
	cin>>t;
	for(ll i = 0;i<t;i++)solve();
}
