#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll l,r;
	cin>>l>>r;
	vector<ll> v(r-l+1);
	for(int i = l;i<=r;i++)cin>>v[i-l];
	ll cnt[2][31];
	memset(cnt,0LL,sizeof(cnt));
	for(ll i = 0;i<r-l+1;i++){
		ll tmp = 0;
		for(ll j = 0;j<31;j++){
			cnt[v[i]&1][j]++;
			v[i]>>=1;
		}
	}
	ll ans = 0;
	for(ll i = 0;i<30;i++){
		if(cnt[0][i]<cnt[1][i]){
			ans ^= (1LL<<i);
		}
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

