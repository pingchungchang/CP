#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll arr[3],brr[3];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	ll ans = min(arr[2],brr[1])*2;
	arr[2] -= ans/2,brr[1]-=ans/2;

	ll d = min(arr[0]+arr[2],brr[2]);
	brr[2] -= d;

	d = min(arr[1],brr[0]+brr[1]);
	arr[1] -= d;

	ans -= min(arr[1],brr[2])*2;
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
