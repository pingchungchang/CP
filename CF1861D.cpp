#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int pdp[n] = {};
	pdp[0] = 0;
	for(int i = 1;i<n;i++){
		pdp[i] += pdp[i-1];
		if(arr[i]>=arr[i-1])pdp[i]++;
	}
	int sdp[n] = {};
	sdp[n-1] = 0;
	for(int i = n-2;i>=0;i--){
		sdp[i] += sdp[i+1];
		if(arr[i]>=arr[i+1])sdp[i]++;
	}
	int ans = sdp[0];
	ans = min(ans,pdp[n-1]+1);
	//for(auto &i:pdp)cout<<i<<' ';
	for(int i = 0;i<n-1;i++){
		ans = min(ans,sdp[i+1]+pdp[i]+1);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
