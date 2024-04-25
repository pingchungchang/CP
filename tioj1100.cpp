#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

struct node{
	ll s,e,p;
	node(){
		s = e = p = 0;
	}
};
ll n;
void solve(){
	vector<ll> all;
	all.push_back(0);
	vector<node> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].s>>v[i].e>>v[i].p;
		all.push_back(v[i].s);
		all.push_back(v[i].e);
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
//	for(auto i:all)cout<<i<<' ';cout<<'\n';
	for(auto &i:v){
		i.s = lower_bound(_all(all),i.s)-all.begin();
		i.e = lower_bound(_all(all),i.e)-all.begin();
	}
	vector<ll> dp(all.size(),0LL);
	for(ll i = 0;i<n;i++){
		for(ll j = v[i].s;j<=v[i].e;j++){
			if(all[j]-v[i].p+1<all[v[i].s])continue;
			ll pos = lower_bound(_all(all),all[j]-v[i].p)-all.begin();
			dp[j] = max(dp[j],dp[pos]+1);
//			cout<<all[j]<<' '<<all[pos]<<'\n';
		}
	}
	cout<<*max_element(_all(dp));
	return;
}
int main(){
	io
	while(cin>>n){
		if(!n)return 0;
		solve();
	}
}
