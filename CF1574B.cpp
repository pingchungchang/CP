#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	ll arr[3];
	for(int i = 0;i<3;i++)cin>>arr[i];
	ll t;
	cin>>t;
	sort(arr,arr+3);
	ll mx = 0;
	for(auto i:arr)mx += i-1;
	ll mn = arr[2]-1-arr[1]-arr[0];
	if(mn<=t&&t<=mx)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

