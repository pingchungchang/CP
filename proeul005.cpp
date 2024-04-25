#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll ans = 1;
	for(ll i = 1;i<=20;i++){
		ans = ans*i/__gcd(ans,i);
	}
	cout<<ans;
}
