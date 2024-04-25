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
	ll od = 0,ev = 0;
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n,[](ll a,ll b){return (a&1)<(b&1);});
	ll ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(__gcd(arr[i],arr[j]*2) != 1)ans++;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
