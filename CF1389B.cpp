#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k,z;
	cin>>n>>k>>z;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	int ans = 0;
	for(int i = 0;i<=z;i++){
		int sum = 0;
		int len = k-i*2;
		if(len<0)break;
		for(int j = 0;j<=len;j++)sum += arr[j];
		ll big = 0;
		for(int j = 1;j<=len;j++)big = max(big,arr[j]+arr[j-1]);
		ans = max(ans,big*i+sum);
	}
	for(int i = 1;i<=z;i++){
		int sum = 0,len = k-i*2+1;
		if(len<=0)break;
		for(int j = 0;j<=len;j++)sum += arr[j];
		ll big = 0;
		for(int j = 1;j<=len;j++)big = max(big,arr[j]+arr[j-1]);
		ans = max(ans,big*(i-1)+arr[len-1]+sum);
	}
	cout<<ans<<'\n';
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
