#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	int k;
	cin>>n>>k;
	int arr[n];
	for(auto &i:arr)cin>>i;
	pii now = {arr[0],arr[0]};
	for(int i = 1;i<n;i++){
		pii tmp;
		tmp.fs = max(arr[i],now.fs-k+1);
		tmp.sc = min(arr[i]+k-1,now.sc+k-1);
		if(tmp.fs>tmp.sc){
			cout<<"NO\n";
			return;
		}
		now = tmp;
	}
	if(now.fs>arr[n-1]||now.sc<arr[n-1])cout<<"NO\n";
	else cout<<"YES\n";
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
