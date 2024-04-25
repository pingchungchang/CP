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
#define int ll
void solve(){
	int n,q;
	cin>>n>>q;
	int arr[n+1];
	arr[n] = 1e18;
	for(int i = 0;i<n;i++)cin>>arr[i	];
	pii req[q];
	for(int i = 0;i<q;i++){
		cin>>req[i].fs;
		req[i].sc = i;
	}
	sort(req,req+q);
	int ans[q];
	int p = 0;
	ll s = 0;
	for(auto &i:arr){
		while(p != q&&i>req[p].fs){
			ans[req[p].sc] = s;
			p++;
		}
		s += i;
	}
	for(int i = 0;i<q;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}
main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

