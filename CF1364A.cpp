#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
	ll n,m;
	cin>>n>>m;
	ll arr[n+1];
	memset(arr,0LL,sizeof(arr));
	ll sm = INT_MAX;
	ll ans = -1;
	for(ll i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] += arr[i-1];
		if(arr[i]%m == 0){
			ans = max(ans,i-sm);
		}
		else{
			ans = i;
			sm = min(sm,i);
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

