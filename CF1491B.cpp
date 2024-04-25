#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	bool flag = 1;
	for(int i = 1;i<n;i++){
		if(arr[i] != arr[i-1])flag = 0;
	}
	if(flag){
		ll ans = a+b;
		ans = min({ans,b*2});
		cout<<ans<<'\n';
		return;
	}
	flag = true;
	for(int i = 1;i<n;i++){
		if(abs(arr[i]-arr[i-1])>1)flag = false;
	}
	if(flag)cout<<min(a,b)<<'\n';
	else cout<<0<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
