#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int l = 0,r = i;
		while(l != r){
			int mid = (l+r)>>1;
			if(arr[mid]>=(i-mid+1))r = mid;
			else l = mid+1;
		}
		cout<<i-l+1<<' ';
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
