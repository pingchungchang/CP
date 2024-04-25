#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld long double

const int mxn = 201;
vector<int> v[mxn];
int cost[mxn];
int n,m;
ld dp[mxn];
bitset<mxn> done;

ld f(int now){
	if(now>=m)return dp[now] = 0;
	if(done[now])return dp[now];
	done[now] = true;
	dp[now] = 1e18;
	for(int i = 0;i<n;i++){
		ld tans = cost[i];
		ld coef = 0;
		for(auto &j:v[i]){
			if(!j)coef++;
			else tans += f(now+j)/v[i].size();
		}
		tans = tans*v[i].size()/(v[i].size()-coef);
		dp[now] = min(dp[now],tans);
	}
	return dp[now];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int k;
		cin>>cost[i];
		cin>>k;
		for(int j = 0;j<k;j++){
			int tmp;
			cin>>tmp;
			v[i].push_back(tmp);
		}
		sort(v[i].begin(),v[i].end());
	}
	cout<<fixed<<setprecision(10)<<f(0);
}
