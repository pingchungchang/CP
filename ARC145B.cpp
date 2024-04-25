#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	if(a<=b){
		cout<<n-min(n,a-1);
	}
	else{
		if(n<a){
			cout<<0;
			return 0;
		}
		ll tmp = n%a;
		ll ans = (n-a)/a*b+min(tmp+1,b);
		cout<<ans;
	}
	return 0;
}

