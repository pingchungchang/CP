#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll k;
	ll c;
	ll a,b;
	cin>>k;
	if((k&1) == 1){
		k -=1;
		k/=2;
		if((k&1) == 1){
			a = k+2;
			b = k-2;
			c = 1;
		}
		else{
			a = k+1;
			b = k-1;
			c = 1;
		}
	}
	else{
		k -= 1;
		k /=2;
		a = k;
		b = k+1;
		c = 1;
	}
	cout<<a<<' '<<b<<' '<<c<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i =0;i<t;i++){
		solve();
	}
}
