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
	int brr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		brr[i] = arr[i];
	}
	sort(arr,arr+n,greater<int>());
	bool same = false;
	for(int i = 0;i<n;i++){
		if(arr[i] != brr[i]){
			cout<<"YES\n";
			return;
		}
		if(i != 0&&arr[i] == arr[i-1])same = true;
	}
	if(same)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
