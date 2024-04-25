#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll mod = 998244353;
int main(){
	ll ans = 0;
	ll n;
	cin>>n;
	for(ll i = 1;i*i<=n;i++){
		ll r = n/i;
		if((r+i)%2 != 0)r--;
		if(r>=i){
			ans += (r-i)/2+1;
		}
//		cout<<i<<' '<<ans<<endl;
		ans %= mod;
	}
	cout<<ans;
}
//x^2-(x-1)^2 = 2x-1
//x*x-z*z = y
//(x-z)(x+z) = y
