#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll arr[3];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+3);
	if(arr[2]>arr[0]+arr[1]){
		cout<<arr[0]+arr[1]<<'\n';
	}
	else cout<<(arr[0]+arr[1]+arr[2])/2<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
