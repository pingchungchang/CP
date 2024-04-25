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
	int cnt = 0;
	int l = 0,r = n-1;
	int x = 0;
	for(int i = 0;i<n;i++){
		if(!x)x = arr[i];
		else x &= arr[i];
		if(!x)cnt++,l = i+1;
	}
	x = 0;
	for(int i = n-1;i>=l;i--){
		if(!x)x = arr[i];
		else x &= arr[i];
		if(!x)cnt++,r = i-1;
	}
	cout<<max(1,cnt)<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
