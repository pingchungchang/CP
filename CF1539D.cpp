#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int n;
vector<pll> v;

bool f(ll k){
	if(k<v[0].fs)return false;
	ll tmp = k;
	for(auto i:v){
		if(i.fs == -1)return true;
		if(tmp<i.fs)return false;
		tmp += i.sc;
	}
	return true;
}
int main(){
	cin>>n;
	v = vector<pll>(n);
	ll total = 0;
	for(int i = 0;i<n;i++){
		cin>>v[i].sc>>v[i].fs;
		total += v[i].sc;
	}
	sort(v.begin(),v.end());
	ll l = 0,r = total;
	ll ans = 0;
	ll mv = 0;
	for(auto &i:v){
		if(total<=i.fs){
			ans += i.sc*2;
			total -= i.sc;
			mv += i.sc;
			i.fs = -1;
		}
	}
	for(auto &i:v){
		if(i.fs != -1){
			i.fs = max(i.fs-mv,0LL);
		}
	}
	while(l != r){
		ll mid = (l+r)/2;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<ans+total+l;
}

