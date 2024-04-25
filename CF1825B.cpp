#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	ll arr[n*m];
	ll ans = 0;
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n*m);
	ans = arr[n*m-1]*(n*m-min(n,m))+arr[n*m-2]*(min(n,m)-1)-arr[0]*(n*m-1);
	ll tmp = arr[n*m-1]*(n*m-1)-arr[0]*(n*m-min(n,m))-arr[1]*(min(n,m)-1);
	cout<<max(ans,tmp)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
