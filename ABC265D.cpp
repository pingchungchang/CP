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
const ll mxn = 2e5+10;

int main(){
	ll n,p,q,r;
	cin>>n>>p>>q>>r;
	ll arr[n+1];
	arr[0] = 0;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i]+= arr[i-1];
	}
	for(int i = 0;i<=n;i++){
		ll pre = i;
		ll pos = lower_bound(arr,arr+n+1,arr[pre]+p)-arr;
		if(pos == n+1||arr[pre]+p != arr[pos])continue;
		pre = pos;
		pos = lower_bound(arr,arr+n+1,arr[pre]+q)-arr;
		if(pos == n+1||arr[pre]+q != arr[pos])continue;
		pre = pos;
		pos = lower_bound(arr,arr+n+1,arr[pre]+r)-arr;
		if(pos == n+1||arr[pre]+r != arr[pos])continue;
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
	return 0;
}

