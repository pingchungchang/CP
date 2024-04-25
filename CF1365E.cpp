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
	ll ans = *max_element(arr,arr+n);
	for(int i =0;i<n;i++)for(int j = i+1;j<n;j++)for(int k = j;k<n;k++){
		ans = max(ans,arr[i]|arr[j]|arr[k]);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
