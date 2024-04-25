#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e4+10;

int n,sum;
vector<int> all;
int cnt[1010];

namespace DP1{
	bitset<mxn*1000> dp;
	void solve(){
		dp.reset();
		dp[0] = true;
		for(auto &i:all)dp = dp|(dp<<i);
		int big = 0;
		for(int i = sum>>1;i>=0;i--){
			if(dp[i]){
				big = i;
				break;
			}
		}
		cout<<abs(sum-big*2)<<'\n';
		return;
	}
}

namespace DP2{
	bool dp[mxn*10];
	void solve(){
		for(int i = 0;i+i<=sum;i++)dp[i] = 0;
		dp[0] = 1;
		int h = sum>>1;
		for(auto &i:all){
			for(int j = i;j<=h;j++)dp[j] = dp[j]|dp[j-i];
		}
		int big = 0;
		for(int i = sum>>1;i>=0;i--){
			if(dp[i]){
				big = i;
				break;
			}
		}
		cout<<abs(sum-big*2)<<'\n';
		return;
	}
}

void solve(){
	sum = 0;
	cin>>n;
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[k]++;
		sum += k;
	}
	all.clear();
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<cnt[i];j<<=1){
			all.push_back(i*j);
			cnt[i] -= j;
		}
		all.push_back(cnt[i]*i);
	}
	if(sum>1e6)DP1::solve();
	else DP2::solve();
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
