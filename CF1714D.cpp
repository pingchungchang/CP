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
#define int ll


struct node{
	ll val,pre,id;
	node(){
		val = INT_MAX;
		pre = id = -1;
	}
	bool operator<(node b)const{
		return val<b.val;
	}
	node operator+(ll k){
		val += k;
		return *this;
	}
};
void solve(){
	string s;
	cin>>s;
	ll m;
	cin>>m;
	int n = s.size();
	vector<string> v(m);
	for(int i = 0;i<m;i++)cin>>v[i];
	vector<node> dp(n+1,node());
	dp[0].val = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<m;j++){
			if(v[j].size()<=i&&s.substr(i-v[j].size(),v[j].size()) == v[j]){
				if(dp[i-v[j].size()].val+1<dp[i].val){
					dp[i].val = dp[i-v[j].size()].val+1;
					dp[i].pre = i-v[j].size();
					dp[i].id = j;
					for(int k = 0;k<v[j].size();k++){
						dp[i-k] = min(dp[i-k],dp[i]);
					}
				}
			}
		}
	}
	ll now = n;
	if(dp[n].val == INT_MAX){
		cout<<"-1\n";
		return;	
	}
	vector<pll> ans;
	while(now != 0){
		ans.push_back(make_pair(dp[now].pre+1,dp[now].id));
		now = dp[now].pre;
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i.sc+1<<' '<<i.fs<<'\n';
	return;	
}
main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

