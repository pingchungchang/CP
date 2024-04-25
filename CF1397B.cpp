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
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	ll ans = 0;
	for(auto &i:arr)ans += i;
	bool flag = true;
	for(ll i = 1;i<1e6&&flag;i++){
		ll now = 1;
		ll tans = 0;
		for(auto &j:arr){
			if(now>1e12){
				flag = false;
				break;
			}
			tans += abs(j-now);
			now*= i;
		}
		if(flag)ans = min(ans,tans);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}
