#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll inf = 1e9+10;

void solve(){
	ll n,len;
	cin>>n>>len;
	pll arr[n];
	vector<ll> all;
	for(auto &i:arr)cin>>i.fs,all.push_back(i.fs);
	all.push_back(-inf);
	for(auto &i:arr)cin>>i.sc;
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	ll dp[all.size()];
	memset(dp,0,sizeof(dp));
	ll pref[all.size()];
	memset(pref,0,sizeof(dp));
	for(auto &i:arr){
		i.fs = lower_bound(all.begin(),all.end(),i.fs)-all.begin();
		pref[i.fs]++;
	}
	for(int i = 1;i<all.size();i++)pref[i] += pref[i-1];
	for(int i = 1;i<all.size();i++){
		auto l = --lower_bound(all.begin(),all.end(),all[i]-len)-all.begin();
		dp[i] = max(dp[i-1],pref[i]-pref[l]);
	}
	//for(int i = 0;i<all.size();i++)cout<<dp[i]<<' ';cout<<'\n';
	for(int i = all.size()-1;i>=1;i--){
		auto l = --lower_bound(all.begin(),all.end(),all[i]-len)-all.begin();
		dp[i] = pref[i]-pref[l]+dp[l];
	}
	cout<<*max_element(dp,dp+all.size())<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
