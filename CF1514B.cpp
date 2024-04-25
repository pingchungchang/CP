#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mod = 1e9+7;
ll pw(ll a,ll b){
	ll ans = 1;
	while(b != 0){
		if(b&1)ans = ans*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return ans;
}
void solve(){
	ll n,k;
	cin>>n>>k;
	cout<<pw(n,k)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

