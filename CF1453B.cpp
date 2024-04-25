#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	ll total = 0;
	for(int i = 1;i<n;i++)total += abs(arr[i]-arr[i-1]);
	ll ans = total;
	for(int i = 1;i<n-1;i++){
		ans = min(ans,total-abs(arr[i]-arr[i-1])-abs(arr[i+1]-arr[i])+abs(arr[i+1]-arr[i-1]));
	}
	if(n>=3)ans = min(ans,total-abs(arr[n-1]-arr[n-2])-abs(arr[n-2]-arr[n-3])+abs(arr[n-2]-arr[n-3]));
	if(n>=3)ans = min(ans,total-abs(arr[0]-arr[1])-abs(arr[1]-arr[2])+abs(arr[1]-arr[2]));
	if(n<3)ans = 0;
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
