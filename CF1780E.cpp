#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll l,r;

void solve(){
	cin>>l>>r;
	ll ans = 0;
	ans += max(0ll,r/2-l+1);
	for(ll s = 1,e;s<l;s= e+1){
		ll c = (l+s-1)/s;
		e = (l+c-2)/(c-1)-1;
		ans += max(0ll,min(e,r/(c+1))-s+1);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
