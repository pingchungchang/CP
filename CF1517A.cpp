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
void solve(){
	ll n;
	cin>>n;
	if(n%2050 != 0){
		cout<<"-1\n";
		return;
	}
	n/=2050;
	ll ans = 0;
	while(n){
		ans += n%10;
		n/=10;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

