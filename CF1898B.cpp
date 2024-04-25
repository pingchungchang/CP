#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
ll arr[mxn];

void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll ans = 0;
	for(int i = n-1;i>=1;i--){
		ll l = 1,r = arr[i];
		while(l != r){
			ll mid = (l+r)>>1;
			if((arr[i]+mid-1)/mid<=arr[i+1])r = mid;
			else l = mid+1;
		}
		ans += l-1;
		arr[i] = arr[i]/l;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
