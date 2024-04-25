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
	ll arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	ll ans = 0;
	ll cnt[n] = {};
	for(int i = 0;i<n;i++){
		if(arr[i]>n-i){
			ans += arr[i]-(n-i);
			cnt[i] -=(arr[i]-(n-i));
			arr[i] = n-i;
		}
		while(arr[i]>1){
			if(i+arr[i]>=n)ans++;
			else cnt[i+arr[i]]++;
			arr[i]--;
			cnt[i]--;
		}
		if(cnt[i]>0){
			if(i+1>=n)ans += cnt[i];
			else cnt[i+1] += cnt[i];
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

