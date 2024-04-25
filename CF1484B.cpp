#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	bool flag = true;
	int d = -1;
	for(int i = 1;i<n;i++){
		if(arr[i]>=arr[i-1]){
			if(d == -1)d = arr[i]-arr[i-1];
			else if(arr[i]-arr[i-1] != d){
				cout<<"-1\n";
				return;
			}
		}
		else flag = false;
	}
	if(flag){
		cout<<"0\n";
		return;
	}
	if(d == -1){
		for(int i = 1;i<n;i++){
			if(d == -1)d = arr[i-1]-arr[i];
			else if(arr[i-1]-arr[i] != d){
				cout<<"-1\n";
				return;
			}
		}
		cout<<"0\n";
		return;
	}
	int m = -1;
	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1])m = arr[i-1]+d-arr[i];
	}
	if(*max_element(arr,arr+n)>=m){
		cout<<"-1\n";
		return;
	}
	for(int i = 1;i<n;i++){
		if((arr[i-1]+d)%m != arr[i]){
			cout<<"-1\n";
			return;
		}
	}
	cout<<m<<' '<<d<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
