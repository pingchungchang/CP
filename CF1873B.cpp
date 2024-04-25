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
	ll ans = 0;
	for(int i= 0;i<n;i++){
		arr[i]++;
		ll pro = 1;
		for(int j = 0;j<n;j++){
			pro *= arr[j];
		}
		ans = max(ans,pro);
		arr[i]--;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
