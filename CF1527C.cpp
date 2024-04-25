#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;++i)cin>>v[i];
	vector<ll> dp(n,0);
	
	map<int,ll> mp;
	mp[v[0]] = 1;
	for(int i = 1;i<n;i++){
		dp[i] = dp[i-1];
		if(mp.count(v[i]) != 0)dp[i]+= mp[v[i]];
		if(mp.count(v[i]) == 0){
			mp[v[i]]=i+1;
		}
		else mp[v[i]]+=i+1;
	}
	ll ans = 0;
	for(auto i:dp){
//		cout<<i<<' ';
		ans += i;
	}
//	cout<<endl;
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
