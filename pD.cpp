#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	ll c;
	cin>>n>>m>>c;
	ll arr[m+2];
	memset(arr,0,sizeof(arr));
	for(int i = 0;i<n-1;i++){
		int a,b,val;
		cin>>a>>b>>val;
		arr[a]+= val;
		arr[b+1] -= val;
	}
	ll biggest = 0;
	ll now = 0;
	for(int i = 1;i<=m+1;i++){
		arr[i] += arr[i-1];
		biggest = max(biggest,arr[i]);
	}
//	for(auto i:arr)cout<<i<<' ';
//	return 0;
	ll v[m+1];
	ll ans = LONG_LONG_MAX;
	for(int  i = 1;i<=m;i++)cin>>v[i];
	for(int i = 1;i<=m;i++){
		if(arr[i]+c>=biggest){
			ans = min(ans,v[i]);
		}
	}
	cout<<ans;
}
