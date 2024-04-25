#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(__gcd(arr[i],arr[j])<=2){
				cout<<"YES\n";
				return;
			}
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
