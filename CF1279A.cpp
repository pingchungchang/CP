#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


void solve(){
	int arr[3];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+3);
	ll sum = arr[0]+arr[1]+arr[2];
	if(arr[2]<=(sum+1)/2)cout<<"Yes\n";
	else cout<<"NO\n";
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
