#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll x;
	cin>>x;
	ll ans = x-1;
	ll a = 1,b = x;
	for(ll i =1;i*i<=x;i++){
		if(x%i == 0&&__gcd(x/i,i) == 1){
			if(ans>max(x/i,i)){
				a = x/i,b = i;
				ans = max(a,b);
			}
		}
	}
	cout<<min(a,b)<<' '<<max(a,b);
}
