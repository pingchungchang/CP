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
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	ll ans = INT_MIN;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = max(0LL,n-k*2-1);i<n;i++){
		for(int j = i+1;j<n;j++){
			ans = max(ans,1LL*(i+1)*(j+1)-k*(arr[i]|arr[j]));
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

