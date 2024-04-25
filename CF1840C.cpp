#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,k,q;
	cin>>n>>k>>q;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll p = 0;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		if(p<i)p = i;
		while(p<n&&arr[p]<=q)p++;
		ans += max(0LL,p-i+1-k);
		//cout<<i<<":"<<p<<'\n';
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
