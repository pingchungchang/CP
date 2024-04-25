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
const ll mxn = 5e5+10;
int main(){
	int n;
	cin>>n;
	int arr[n+1];
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int same = 0;
	for(int i = 1;i<=n;i++){
		if(i == arr[i])same++;
		else if(i<arr[i]&&arr[arr[i]] == i)ans++;
	}
	ans += 1LL*same*(same-1)/2;
	cout<<ans;
}

