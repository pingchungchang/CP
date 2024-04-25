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
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		arr[i] -= k;
	}
	pii range = {n,-1};
	for(int i = 0;i<n;i++){
		if(arr[i])range.fs = min(range.fs,i),range.sc = max(range.sc,i);
		if(arr[i]>0){
			cout<<"NO\n";
			return;
		}
	}
	for(int i = range.fs;i<=range.sc;i++){
		if(arr[i] != arr[range.sc]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
