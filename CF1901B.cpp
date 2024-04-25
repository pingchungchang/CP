#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
ll arr[mxn];
ll n;

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll ans = 0;
	ans = arr[1];
	for(int i = 2;i<=n;i++)ans += max(0ll,arr[i]-arr[i-1]);
	cout<<ans-1<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
