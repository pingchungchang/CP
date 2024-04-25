#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,a,b;
	cin>>n>>a>>b;
	if(a == b){
		cout<<"0\n";
		return;
	}
	ll L = a*b/__gcd(a,b);
	ll c1 = n/a-n/L;
	ll c2 = n/b-n/L;
	ll ans = (n+n-c1+1)*(c1)/2-(1LL+1LL+c2-1)*c2/2;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
