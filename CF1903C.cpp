#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 1e5+10;
ll arr[mxn],pref[mxn];
ll n;

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	reverse(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1]+arr[i];
	}
	ll big = 0;
	ll dp;
	for(int i = 1;i<=n;i++){
		dp = big+pref[i];
		big = max(big,dp);
	}
	cout<<dp<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
