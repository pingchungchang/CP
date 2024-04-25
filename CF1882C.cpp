#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	ll arr[n+1] = {0};
	ll sum = 0;
	for(int i = 1;i<=n;i++)cin>>arr[i],sum += arr[i]>0?arr[i]:0LL;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(arr[i]>0)sum -= arr[i];
		if(i&1)ans = max(ans,sum+arr[i]);
		else ans = max(ans,sum);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
