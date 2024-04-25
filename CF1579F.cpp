#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,d;
	cin>>n>>d;
	vector<int> v(n,0);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<bool> goneto(n,0);
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(goneto[i])continue;
		int now = i;
		vector<int> tmp;
		while(!goneto[now]){
			goneto[now] = true;
			tmp.push_back(now);
			now = (now+d)%n;
		}
		int k = tmp.size();
		for(int j = 0;j<k;j++)tmp.push_back(tmp[j]);
		int pre = 0;
		int dp = 0;
		for(auto &j:tmp){
			if(v[j] == 1){
				pre++;
			}
			else pre = 0;
			dp = max(dp,pre);
		}
		if(dp >= k)ans = INT_MAX;
		ans = max(ans,dp);
	}
	if(ans == INT_MAX)cout<<"-1\n";
	else cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

