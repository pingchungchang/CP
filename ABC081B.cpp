#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll ord(ll k){
	ll ans = 0;
	while(!(k&1)){
		k>>=1;
		ans++;
	}
	return ans;
}
int main(){
	ll n;
	cin>>n;
	ll ans = INT_MAX;
	for(ll i =0;i<n;i++){
		ll k;
		cin>>k;
		ans = min(ans,ord(k));
	}
	cout<<ans;
}

