#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	int l = 0,r = n-1;
	for(int i= 0;i<n;i++){
		if(arr[i] != 1)break;
		l = i;
	}
	for(int i = n-1;i>=0;i--){
		if(arr[i] != 1)break;
		r = i;
	}
	if(l>=r)cout<<0<<'\n';
	else cout<<(r-l)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

