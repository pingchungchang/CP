#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e6+10;
ll pdp[mxn],sdp[mxn],arr[mxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	pdp[1] = max(0LL,arr[1]);
	for(int i = 2;i<=n;i++){
		pdp[i] = max(arr[i]+pdp[i-2],pdp[i-1]);
	}
	sdp[n] = max(0LL,arr[n]);
	for(int i = n-1;i>=1;i--){
		sdp[i] = max(arr[i]+sdp[i+2],sdp[i+1]);
	}
	ll ans = max(pdp[n],sdp[1]);
	cout<<ans;
}
