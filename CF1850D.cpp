#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int l = 0;
	int ans = n-1;
	for(int i = 1;i<n;i++){
		if(arr[i]-arr[i-1]>k){
			ans = min(ans,n-(i-l));
			l = i;
		}
	}
	ans = min(ans,n-(n-l));
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
