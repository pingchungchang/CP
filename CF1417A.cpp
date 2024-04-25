#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int ans = 0;
	if(arr[n-1]>k){
		cout<<"0\n";
		return;
	}
	for(int i = 1;i<n;i++){
		ans += (k-arr[i])/arr[0];
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
