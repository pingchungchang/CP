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

void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	int ans = 0;
	for(int i = k;i<n;i++)if(arr[i]<=k)ans++;
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

