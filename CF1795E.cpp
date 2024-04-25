#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;
deque<pll> dq;
ll range[mxn];
ll dp[mxn],dp2[mxn];
ll pref[mxn];
ll arr[mxn];
ll ans[mxn];
int n;

inline ll calc(ll l,ll r){
	ll len = r-l;
	if(len>arr[r]){
		return arr[r]*arr[r]-(arr[r]+1)*arr[r]/2;
	}
	else return arr[r]*(len-1)-(len)*(len-1)/2+arr[l];
}

void solve(){
	dq.clear();
	for(int i  = 0;i<=n;i++)arr[i] = 0,dp[i] = 0,ans[i] = 0,dp2[i] = 0;

	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<=n+1;i++)pref[i] = pref[i-1]+arr[i];
	for(int i = 1;i<=n;i++)ans[i] = pref[n];

	dq.clear();
	dq.push_back(make_pair(-mxn*10,0));
	for(int i = 1;i<=n;i++){
		while(dq.back().fs>arr[i]-i)dq.pop_back();
		int r = dq.back().sc;
		//cout<<i<<":"<<r<<endl;
		ll& tdp = dp[i];
		tdp += calc(r,i)+dp[r];
		dq.push_back(make_pair(arr[i]-i,i));
	}
	//for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;

	reverse(arr+1,arr+n+1);
	dq.clear();
	dq.push_back(make_pair(-mxn*10,0));
	for(int i = 1;i<=n+1;i++)pref[i] = pref[i-1]+arr[i];
	for(int i = 1;i<=n;i++){
		while(dq.back().fs>arr[i]-i)dq.pop_back();
		int r = dq.back().sc;
		ll& tdp = dp2[i];
		tdp += calc(r,i)+dp2[r];
		dq.push_back(make_pair(arr[i]-i,i));
	}
	//for(int i = 1;i<=n;i++)cout<<dp2[n+1-i]<<' ';cout<<endl;

	for(int i = 1;i<=n;i++)ans[i] -= dp[i]+dp2[n+1-i];
	cout<<*min_element(ans+1,ans+n+1)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
