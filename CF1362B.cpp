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
	for(int i = 1;i<1024;i++){
		int brr[n];
		for(int j = 0;j<n;j++)brr[j] = arr[j]^i;
		sort(brr,brr+n);
		sort(arr,arr+n);
		bool flag = true;
		for(int j = 0;j<n;j++){
			if(arr[j] != brr[j])flag = false;
		}
		if(flag){
			cout<<i<<'\n';
			return;
		}
	}
	cout<<"-1\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
