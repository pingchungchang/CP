#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll __int128_t

int main(){
	int n;
	cin>>n;
	vector<ll> v(n);
	for(auto &i:v){
		int k;
		cin>>k;
		i = (__int128_t)k;
	}
	ll ans = 0;
	for(int i = 0;i<n/2*2;i+= 2){
		ll l = 0,r = 0;
		ll small = 1;
		for(int j = i;j<n/2*2;j+=2){
			l += v[j],r += v[j+1];
			ll la = l-v[i],ra = r-v[j+1];
			ll lm=0,rm = 0;
			if(la<ra)lm = ra-la;
			else rm = la-ra;
			if(small+la>r);
			else ans += max((ll)0,min({v[i]-lm,v[j+1]-rm,v[i]-small+1}));
			cout<<i<<' '<<j<<' '<<(int)l<<' '<<(int)r<<' '<<(int)small<<" "<<(int)la<<' '<<(int)ra<<' '<<(int)ans<<endl;
			small = max(small,(r-l+v[i]));
			if(r>l)break;
		}
	}
	string s = to_string((unsigned long long)ans);
	cout<<s;
	
}
