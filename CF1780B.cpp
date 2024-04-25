#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin>>n;
	ll arr[n];
	ll pref = 0,total = 0;
	for(auto &i:arr)cin>>i,total += i;
	ll ans = 0;
	for(auto &i:arr){
		pref += i;
		total -= i;
		if(total != 0)ans = max(ans,__gcd(pref,total));
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
