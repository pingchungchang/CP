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
	pii arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	sort(arr,arr+n);
	int ans = arr[0].fs-1;
	int r = 400;
	for(auto &i:arr){
		r = min(r,i.fs+(i.sc-1)/2);
	}
	cout<<r<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
