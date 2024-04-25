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
	sort(arr,arr+n);
	sort(brr,brr+n);
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	for(auto &i:brr)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
