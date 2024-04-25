#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr){
		cin>>i;
	}
	ll ans = max(0LL,-1LL*arr[0]);
	for(int i = 1;i<n;i++){
		arr[i] += arr[i-1];
		ans = max(ans,-1LL*arr[i]);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
