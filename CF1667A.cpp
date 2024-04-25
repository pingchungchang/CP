#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n;
	cin>>n;
	ll arr[n+1] = {};
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	ll ans = LONG_LONG_MAX;
	for(int i = 0;i<=n;i++){
		ll sm = 1;
		ll tmp = 0;
		for(int j = i-1;j>=1;j--){
			ll diff = (sm+arr[j]-1)/arr[j];
			tmp += diff;
			sm = diff*arr[j]+1;
		}
		sm = 1;
		for(int j = i+1;j<=n;j++){
			ll diff = (sm+arr[j]-1)/arr[j];
			tmp += diff;
			sm = diff*arr[j]+1;
		}
		ans = min(ans,tmp);
	}
	cout<<ans;
}

