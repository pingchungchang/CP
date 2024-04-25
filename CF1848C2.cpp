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
	int arr[n],brr[n];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	auto sum = [&](){
		ll s = 0;
		for(auto &i:arr)s += i;
		return s;
	};
	while(sum() != 0){
		for(int i = 0;i<n;i++)swap(arr[i],brr[i]);
		for(int i = 0;i<n;i++)brr[i] = abs(brr[i]-arr[i]);
		for(auto &i:brr)cout<<i<<' ';
		cout<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
