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
	int arr[n*2];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n*2);
	int ans = 1e9;
	for(int i = 0;i<n;i++)ans = min(ans,arr[n]-arr[i]);
	for(int i = n;i<n*2;i++)ans = min(ans,arr[i]-arr[n-1]);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
