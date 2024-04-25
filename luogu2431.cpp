#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll l,r;
	cin>>l>>r;
	ll ans = 0;
	ll tmp = 0;
	for(ll i = 63;i>=0;i--){
		if(((1ll<<i)&l)&&((1ll<<i)&r))tmp ^= 1ll<<i;
		else if(!((1ll<<i)&r))continue;
		else{
			ans = max(ans,__builtin_popcountll(tmp)+max(0ll,i));
		}
		tmp |= 1ll<<i;
	}
	ans = max({ans,1ll*__builtin_popcountll(l),1ll*__builtin_popcountll(r)});
	cout<<ans;
}
