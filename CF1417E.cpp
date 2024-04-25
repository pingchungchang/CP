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
	vector<int> v(n);
	vector<vector<int>> dp[2];
	ll ans = 0;
	bool roll = false;
	for(auto &i:v)cin>>i;
	dp[roll].push_back(v);
	int x = 0;
	for(ll i = 30;i>=0;i--){
		ll sum[2] = {0,0};
		dp[roll^1].clear();
		//cout<<i<<":";
		for(auto &j:dp[roll]){
			if(j.empty())continue;
			ll cnt[2] = {0,0};
			vector<int> vv[2];
			for(auto &k:j){
				//cout<<k<<' ';
				if(k&(1<<i)){
					sum[1] += cnt[0];
					cnt[1]++;
					vv[1].push_back(k);
				}
				else{
					sum[0] += cnt[1];
					cnt[0]++;
					vv[0].push_back(k);
				}
			}
			//cout<<'\n';
			dp[roll^1].push_back(vv[0]);
			dp[roll^1].push_back(vv[1]);
		}
		if(sum[0]>sum[1])x ^= 1<<i;
		ans += min(sum[0],sum[1]);
		roll ^= 1;
	}
	cout<<ans<<' '<<x;
}
