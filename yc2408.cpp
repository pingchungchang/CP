#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll ans = 0;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		ll pos = lower_bound(arr,arr+n,a)-arr;
		ll tmp = b;
		if(pos != n)tmp = max(tmp,c-(arr[pos]-a));
		if(pos != 0)tmp = max(tmp,c-(a-arr[pos-1]));
		ans += tmp;
	}
	cout<<ans;
}
