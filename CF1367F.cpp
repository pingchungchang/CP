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
	vector<int> all;
	int arr[n];
	for(auto &i:arr)cin>>i,all.push_back(i);
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for(auto &i:arr)i = lower_bound(all.begin(),all.end(),i)-all.begin();
	pii range[all.size()];
	vector<int> pos[all.size()];
	for(auto &i:range)i.fs = n,i.sc = -1;
	for(int i = 0;i<n;i++){
		pii &r = range[arr[i]];
		pos[arr[i]].push_back(i);
		r.fs = min(r.fs,i);
		r.sc = max(r.sc,i);
	}
	int dp[all.size()] = {};
	dp[0] = pos[0].size();
	for(int i = 1;i<all.size();i++){
		if(range[i].fs>range[i-1].sc){
			dp[i] = dp[i-1]+pos[i].size();
			continue;
		}
		int p = upper_bound(pos[i-1].begin(),pos[i-1].end(),range[i].fs)-pos[i-1].begin();
		dp[i] = pos[i].size()+p;
	}
	int ans = *max_element(dp,dp+all.size());
	for(int i = 0;i<all.size()-1;i++){
		int p = upper_bound(pos[i+1].begin(),pos[i+1].end(),range[i].sc)-pos[i+1].begin();
		ans = max(ans,(int)pos[i+1].size()-p+dp[i]);
	}
	for(int i = 1;i<all.size();i++){
		int s = pos[i].size();
		for(int j = 0;j<pos[i].size();j++){
			int p = lower_bound(pos[i-1].begin(),pos[i-1].end(),pos[i][j])-pos[i-1].begin();
			ans = max(ans,s-j+p);
		}
	}
	cout<<n-ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
