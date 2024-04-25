#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll cnt(ll n){
	ll returns = 0;
	while(n != 0){
		n>>=1;
		returns++;
	}
	return returns;
}
int main(){
	ll n;
	bool t = false;
	while(cin>>n){
		t = true;
		cout<<cnt(n)<<'\n';
	}
}

