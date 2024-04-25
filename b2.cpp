#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 5e7+10;
ll arr[mxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)arr[i] += arr[i-1];
	int p = 1;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(p<i)p = i;
		while(p<=n&&arr[p]-arr[i-1]<=m)p++;
		ans += p-i;
	}
	cout<<ans;
}
