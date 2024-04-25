#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<n;i++){
		arr[i] = arr[i]-arr[i-1];
	}
	ll cnt = 0;
	for(int i = 1;i<n-1;i++){
		if(arr[i]<0){
			arr[0] += arr[i];
			arr[i] = 0;
		}
	}
	for(int i = 1;i<n;i++)arr[i] += arr[i-1];
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	if(arr[0]<0){
		cout<<"NO\n";
		return;
	}
	for(int i = n-2;i>=0;i--)arr[i] = arr[i]-arr[i+1];
	for(int i = n-2;i>=0;i--){
		if(arr[i]<0){
			arr[n-1] += arr[i];
			arr[i] = 0;
		}
	}
	for(int i = 0;i<n;i++){
		if(arr[i] != 0){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

