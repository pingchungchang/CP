#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll n;

void solve(){
	cin>>n;
	ll ans = 0;
	for(ll i = 1;i<=n/2+1;i++){
		ans += (i-1)*((i*2-1)*(i*2-1)-(i*2-3)*(i*2-3));
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
