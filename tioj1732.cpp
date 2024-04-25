#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll n;

void solve(){
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	ll p = arr[n/2];
	ll ans = 0;
	for(auto &i:arr)ans += abs(i-p);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
