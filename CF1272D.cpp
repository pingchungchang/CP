#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n+2];
	arr[0] = 1e9+10,arr[n+1] = 0;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	int pdp[n+2] = {};
	int sdp[n+2] = {};
	for(int i = 1;i<=n+1;i++){
		if(arr[i]>arr[i-1])pdp[i] = pdp[i-1]+1;
		else pdp[i] = 1;
	}
	for(int i = n;i>=1;i--){
		if(arr[i]<arr[i+1])sdp[i] = sdp[i+1]+1;
		else sdp[i] = 1;
	}
	int ans = *max_element(pdp,pdp+n+1);
	for(int i = 1;i<=n;i++){
		if(arr[i-1]<arr[i+1])ans = max(ans,pdp[i-1]+sdp[i+1]);
	}
	cout<<ans;
}
