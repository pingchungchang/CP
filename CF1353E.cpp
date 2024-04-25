#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int calc(vector<int>&v){
	if(v.empty())return 0;
	int n = v.size();
	int dp[n] = {},suf[n+1] = {},pref[n+1] = {};
	for(int i = n-1;i>=0;i--){
		suf[i] = suf[i+1]+v[i];
	}
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1]+v[i-1];
	}
	int re = suf[0];
	for(int i = 0;i<n;i++){
		if(i)dp[i] = min(dp[i-1],pref[i])+(v[i] != 1);
		else dp[i] = (v[i] != 1);
		re = min(re,dp[i]+suf[i+1]);
	}
	return re;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v[k];
	int cnt[k] = {},total = 0;
	int ans = 1e9;
	string s;
	cin>>s;
	for(int i = 0;i<n;i++){
		v[i%k].push_back(s[i]-'0');
		if(s[i] == '1')cnt[i%k]++,total++;
	}
	for(int i = 0;i<k;i++){
		ans = min(ans,total-cnt[i]+calc(v[i]));
		//cout<<calc(v[i])<<endl;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
