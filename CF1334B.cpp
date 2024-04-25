#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);reverse(arr,arr+n);
	ll total = 0;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		total += arr[i];
		if(total>=x*(i+1))ans = i+1;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
