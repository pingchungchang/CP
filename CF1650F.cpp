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
const ll inf = 1e12;
struct node{
	ll t,p,id;
	node(){}
	node(ll ii,ll pp,ll tt):id(ii),p(pp),t(tt){}
};
void solve(){
	int n,m;
	cin>>n>>m;
	ll arr[n+1];
	vector<node> v[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 0;i<m;i++){
		ll e,p,t;
		cin>>e>>t>>p;
		v[e].push_back(node(i+1,p,t));
	}
	vector<ll> ans[n+1];
	ll times[n+1];
	for(int i = 1;i<=n;i++){
		vector<vector<node>> dp(v[i].size()+1,vector<node>(101,node(-1,inf,inf)));
		dp[0][0] = node(-1,0,0);
		for(int j = 0;j<v[i].size();j++){
			auto now = v[i][j];
			for(int k = 0;k<=100;k++){
				dp[j+1][k] = dp[j][k];
				if(now.p>k){
					if(now.t<dp[j+1][k].t){
						dp[j+1][k] = now;
						dp[j+1][k].id = j+1;
					}
				}
				else{
					if(now.t+dp[j][k-now.p].t<dp[j+1][k].t){
						dp[j+1][k].t = now.t+dp[j][k-now.p].t;
						dp[j+1][k].p = now.p;
						dp[j+1][k].id = j+1;
					}
				}
			}
		}
//			cout<<i<<":";
		ll p1 = v[i].size(),p2 = 100;
//		cout<<i<<",";
		while(p1>0&&p2>0){
//				cout<<p1<<' '<<p2<<',';
			ans[i].push_back(v[i][dp[p1][p2].id-1].id);
			ll a = dp[p1][p2].id-1;
			ll b = p2-dp[p1][p2].p;
			p1 = a,p2 = b;
		}
//			cout<<'\n';
		times[i] = dp.back()[100].t;
	}
	ll total = 0;
	for(int i = 1;i<=n;i++){
		total += times[i];
		if(total>arr[i]){
			cout<<"-1\n";
			return;
		}
	}
	total = 0;
	for(auto &i:ans)total += i.size();
	cout<<total<<'\n';
	for(auto &i:ans)for(auto &j:i)cout<<j<<' ';
	cout<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

