#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin>>n;
	ll sum = 0;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		sum += k;
	}
	if(sum%n == 0)cout<<0<<'\n';
	else cout<<1<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		solve();
	}
}
