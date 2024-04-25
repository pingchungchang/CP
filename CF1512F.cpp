#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 2e5+10;
ll arr[mxn],brr[mxn];

void solve(){
	ll n;
	cin>>n;
	ll C;
	cin>>C;
	ll ans = 5e18;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<n;i++)cin>>brr[i];
	pll now = {0,0};
	for(int i = 1;i<=n;i++){
		ans = min(ans,now.sc+max(0LL,(C-now.fs+arr[i]-1)/arr[i]));
		ll days = max(0LL,(brr[i]-now.fs+arr[i]-1)/arr[i]);
		now.sc += days+1;
		now.fs += days*arr[i];
		now.fs -= brr[i];
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
