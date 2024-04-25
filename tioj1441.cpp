#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#pragma GCC optimize("O3")
const ll mxn = 1e6+10;
ll n;
ll total;
vector<ll> prebit,sufbit;
ll pref(ll p){
	ll ans = 0;
	for(;p>0;p -= p&-p)ans = max(ans,prebit[p]);
	return ans;
}
ll suff(ll p){
	ll ans = 0;
	for(;p>0;p -= p&-p)ans = max(ans,sufbit[p]);
	return ans;
}
void addpref(ll p,ll val){
	for(;p<=total;p += p&-p)prebit[p] = max(prebit[p],val);
	return;
}
void addsuff(ll p,ll val){
	for(;p<=total;p += p&-p)sufbit[p] = max(sufbit[p],val);
	return;
}
int main(){
	io
	cin>>n;
	ll v[n+1];
	memset(v,0LL,sizeof(v));
	vector<ll> all;
	for(int i = 1;i<=n;i++){
		cin>>v[i];
		all.push_back(v[i]);
	}
	all.push_back(0LL);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(auto &i:v)i = lower_bound(all.begin(),all.end(),i)-all.begin()+1;
	total = all.size();
	prebit = vector<ll>(total+10,0LL);
	sufbit = vector<ll>(total+10,0LL);
	vector<vector<ll>> dp(2,vector<ll>(n+1,0LL));
//	cout<<endl<<endl;
//	for(auto i:v)cout<<i<<' ';cout<<endl<<endl;
	for(ll i = 1;i<=n;i++){
		ll small = pref(v[i]-1);
		ll big = suff(total-v[i]);
		dp[0][i] = dp[1][big]+1;
		dp[1][i] = dp[0][small]+1;
		dp[1][i] = max(dp[1][i],dp[1][i-1]);
		dp[0][i] = max(dp[0][i],dp[0][i-1]);
//		cout<<big<<' '<<small<<endl;
		addpref(v[i],i);
		addsuff(total-v[i]+1,i);
	}
	
//	for(int i = 1;i<=n;i++){
//		cout<<dp[0][i]<<' '<<dp[1][i]<<',';
//	}
	ll ans = (dp[1][n]%2 == 0?dp[1][n]-1:dp[1][n]);
	if(dp[0][n]%2 == 0)ans = max(ans,dp[0][n]-1);
	else ans = max(ans,dp[0][n]-2);
	cout<<ans;
}

