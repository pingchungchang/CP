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
	int arr[n];
	for(auto &i:arr)cin>>i;
	int ans = (arr[1]-arr[0])/2+1;
	bool flag = false;
	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1])flag = true;
	}
	if(flag){
		cout<<"0\n";
		return;
	}
	for(int i = 1;i<n;i++){
		ans = min(ans,(arr[i]-arr[i-1])/2+1);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
