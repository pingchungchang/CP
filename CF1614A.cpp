#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	ll n,l,r,k;
	cin>>n>>l>>r>>k;
	ll arr[n];
	ll ans =0;
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	for(auto &i:arr){
		if(i>=l&&i<=r&&k>=i){
			k -= i;
			ans++;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

