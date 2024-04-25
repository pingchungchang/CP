#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n],brr[n];
	for(int i = 1;i<n;i++)cin>>arr[i];
	for(auto &i:brr)cin>>i;
	sort(brr,brr+n);
	sort(arr+1,arr+n);
	int ptr[n] = {};
	ptr[n-1] = n-1;
	ll pans = n;
	for(int i = n-1;i>=1;i--){
		if(i != n-1)ptr[i] = ptr[i+1];
		if(ptr[i]>=0&&arr[i]<brr[ptr[i]]){
			ptr[i]--;
			pans--;
		}
	}
	int pt = 0;
	ll ans = 0;
	if(ptr[1]>=0){
		ans += min({brr[ptr[1]]-1,arr[1],m});
	}
	for(int i = 1;i<n-1;i++){
		while(pt<n&&arr[i]>=brr[pt])pt++;
		if(pt<n&&arr[i]<brr[pt])pt++;
		if(pt>ptr[i+1])continue;
		if(ptr[i+1] != -1)ans += max(0ll,min({brr[ptr[i+1]]-1,arr[i+1],m})-arr[i]);
	}
	while(pt<n&&arr[n-1]>=brr[pt])pt++;
	if(pt<n&&arr[n-1]<brr[pt])pt++;
	//cout<<pt<<'\n';
	if(pt<n){
		ans += max(0ll,min({brr[n-1]-1,m})-arr[n-1]);
	}
	cout<<1ll*m*pans-ans<<'\n';
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
