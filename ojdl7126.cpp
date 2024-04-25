#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 1e5+10;
pll dp[mxn];
ll n,tar,q;
ll arr[mxn];
int pre[mxn];
vector<int> no[mxn];
multiset<int> st;

inline pll calc(ll p){
	for(auto &i:dp)i = {0ll,0ll};
	for(int i = 1;i<=n;i++){
		dp[i] = dp[i-1];
		ll lst = pre[i];
		pll tmp = make_pair(dp[lst].fs+arr[i]-p,dp[lst].sc+1);
		dp[i] = max(tmp,dp[i]);
	}
	return dp[n];
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>tar>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	while(q--){
		int l,r;
		cin>>l>>r;
		no[l].push_back(l);
		no[r+1].push_back(-l);
	}
	for(int i = 1;i<=n;i++){
		pre[i] = i-1;
		while(!no[i].empty()){
			auto tmp = no[i].back();
			no[i].pop_back();
			if(tmp>0)st.insert(tmp);
			else st.erase(st.find(-tmp));
		}
		if(!st.empty())pre[i] = min(pre[i],*st.begin()-1);
	}
	ll l = -1e14,r = 1e14;
	while(l != r){
		ll mid = l+(r-l+1)/2;
		pll re = calc(mid);
		if(re.sc>=tar)l = mid;
		else r = mid-1;
	}
	pll re = calc(l);
	ll ans = re.fs+l*tar;
	re = calc(0);
	if(re.sc<=tar)ans = max(ans,re.fs);
	cout<<ans;
}
