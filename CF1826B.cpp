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
	int ans = 0;
	for(int i = 0;i<n/2;i++){
		if(arr[i] == arr[n-1-i])continue;
		else{
			if(ans == 0)ans = abs(arr[i]-arr[n-1-i]);
			else ans = __gcd(ans,abs(arr[i]-arr[n-1-i]));
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
