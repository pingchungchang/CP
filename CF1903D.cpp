#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
ll n,q;
ll arr[mxn];
ll cp[mxn];


void solve(){
	for(int i = 1;i<=n;i++)arr[i] = cp[i];
	ll cnt;
	cin>>cnt;
	ll ans = 0;
	for(ll i = 60;i>=0;i--){
		ll need  = 0;
		for(int j = 1;j<=n;j++){
			need += max(0ll,(1ll<<i)-arr[j]);
			if(need>=(1ll<<60))break;
		}
		for(int j = 1;j<=n;j++){
			if(need<=cnt){
				arr[j] = max(arr[j],1ll<<i);
			}
			if(arr[j]&(1ll<<i))arr[j]^= 1ll<<i;
		}
		if(need<=cnt){
			cnt -= need;
			ans |= 1ll<<i;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i],cp[i] = arr[i];
	while(q--)solve();
}
