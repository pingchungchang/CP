#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll arr[3],n;
	for(auto &i:arr)cin>>i;
	cin>>n;
	sort(arr,arr+3);
	n -= arr[2]*2-arr[0]-arr[1];
	if(n<0)cout<<"NO\n";
	else if(n%3 != 0)cout<<"NO\n";
	else cout<<"Yes\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
