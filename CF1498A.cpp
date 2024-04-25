#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

ll calc(ll k){
	ll G = k;
	ll sum = 0;
	while(k){
		sum += k%10;
		k/=10;
	}
	return __gcd(G,sum);
}

void solve(){
	ll k;
	cin>>k;
	while(calc(k) == 1)k++;
	cout<<k<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
