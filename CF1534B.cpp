#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n;
	cin>>n;
	int arr[n+2] = {};
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll cnt = 0;
	for(int i = 1;i<=n;i++){
		if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
			cnt += arr[i]-max(arr[i-1],arr[i+1]);
			arr[i] = max(arr[i-1],arr[i+1]);
		}
	}
	for(int i = 1;i<=n;i++){
		cnt += abs(arr[i]-arr[i-1]);
	}
	cnt += arr[n];
	cout<<cnt<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

