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
int main(){
	io
	int n;
	cin>>n;
	int s;
	cin>>s;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int p = lower_bound(arr,arr+n,s)-arr;
	int ans = 0;
	for(int i = p;i<n;i++){
		ans += arr[i]-s;
	}
	for(int i = 0;i<p;i++){
		ans += arr[n-1]-s+arr[n-1]-arr[i];
	}
	int ans2 = 0;
	for(int i = 0;i<p;i++){
		ans2 += s-arr[i];
	}
	for(int i = p;i<n;i++){
		ans2 += arr[i]-arr[0]+s-arr[0];
	}
	cout<<ans<<' '<<ans2;
	cout<<min(ans,ans2);
}

