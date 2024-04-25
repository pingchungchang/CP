#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll ans = 0;
	ll now = 1;
	for(int i = 0;i<64;i++){
		int k;
		cin>>k;
		if(k)ans ^= now;
		now<<=1;
	}
	cout<<ans;
}
