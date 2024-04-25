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
#pragma GCC optimize("O3")
void solve(){
	int n;
	cin>>n;
	if(n>45){
		for(int i = 0;i<n;i++){
			int k;
			cin>>k;
		}
		cout<<"YES\n";
		return;
	}
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	for(int i = 0;i<n-2;i++){
		if(arr[i]+arr[i+1]>arr[i+2]){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

