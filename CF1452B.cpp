#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	ll total = 0;
	ll sum = 0;
	for(auto &i:arr)total += arr[n-1]-i,sum += i;
	ll ans = max(0LL,total-(arr[n-1]-arr[0])-arr[0]);
	ans = max(ans,(sum+n-2)/(n-1)*(n-1)-sum);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
