#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	ll ans = n;
	for(ll i = 1;i*i<=n;i++){
		if(n%i == 0){
			if(i<=k)ans = min(ans,n/i);
			ll tmp = n/i;
			if(tmp<=k)ans = min(ans,i);
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
