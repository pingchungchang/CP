#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
int n;
ll arr[mxn],dp[mxn],pref[mxn];

inline bool f(ll tar){
	deque<int> dq;
	dq.push_back(0);
	for(int i = 1;i<=n;i++){
		while(pref[i-1]-pref[dq.front()]>tar)dq.pop_front();
		dp[i] = arr[i]+dp[dq.front()];
		while(dp[dq.back()]>=dp[i])dq.pop_back();
		dq.push_back(i);
	}
	for(int i = n;i>=1&&pref[n]-pref[i]<=tar;i--){
		if(dp[i]<=tar)return true;
	}
	return false;
}

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],pref[i] = pref[i-1]+arr[i];
	ll l = 0,r = 1e18;
	while(l != r){
		ll mid = (l+r)>>1;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
