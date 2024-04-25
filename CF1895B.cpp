#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	int arr[n*2];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n*2);
	ll ans = 0;
	ans = arr[n-1]-arr[0]+arr[n*2-1]-arr[n];
	cout<<ans<<'\n';
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<' '<<arr[i+n]<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
