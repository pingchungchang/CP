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
	int n;
	cin>>n;
	int arr[n+2] = {},pref[n+2] = {},suf[n+2] = {};
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		pref[i] = pref[i-1];
		if(arr[i])pref[i]++;
	}
	for(int i = n;i>=1;i--){
		suf[i] = suf[i+1];
		if(!arr[i])suf[i]++;
	}
	ll ans = INT_MAX;
	for(int i = 1;i<=n;i++){
		ans = min(ans,1LL*max(pref[i-1],suf[i+1]));
//		cout<<i<<' '<<pref[i-1]+suf[i+1]<<',';
	}
	cout<<ans<<'\n';return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

