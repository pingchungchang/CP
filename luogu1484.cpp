#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 3e5+10;
ll n,tar;
ll arr[mxn];

pll calc(ll sh){
	pll dp[2];
	for(auto &i:dp)i = {0ll,0ll};
	for(int i = 1;i<=n;i++){
		pll tmp[2];
		for(auto &i:tmp)i = {0ll,0ll};
		tmp[0] = max(dp[0],dp[1]);
		tmp[1] = max(tmp[1],tmp[0]);
		tmp[1] = max(tmp[1],make_pair(dp[0].fs+arr[i]-sh,dp[0].sc+1));
		dp[0] = tmp[0];
		dp[1] = tmp[1];
	}
	return max(dp[0],dp[1]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>tar;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll l = -1e12,r = 1e12;
	while(l != r){
		ll mid = l+(r-l+1)/2;
		pll tmp = calc(mid);
		//cout<<mid<<":"<<tmp.fs<<' '<<tmp.sc<<endl;
		if(tmp.sc>=tar)l = mid;
		else r = mid-1;
	}
	pll re = calc(l);
	ll ans = re.fs+re.sc*l-(re.sc-tar)*l;
	re = calc(0ll);
	if(re.sc<=tar)ans = max(ans,re.fs);
	cout<<ans;
}
