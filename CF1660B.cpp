#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	if(n == 1){
		if(arr[0] == 0||arr[0] == 1)cout<<"Yes\n";
		else cout<<"No\n";
		return;
	}
	if(arr[n-1]-arr[n-2]>1){
		cout<<"No\n";
	}
	else cout<<"Yes\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i =0 ;i<t;i++)solve();
}

