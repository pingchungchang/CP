#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

ll n;
const int mxn = 3030;
const ll inf = 1e18;
ll arr[mxn];
ll dp[mxn][mxn];

ll f(ll s,ll e,int t){
	if(dp[s][e] != inf)return dp[s][e];
	if(s == e)return dp[s][e] = arr[s];
}

int main(){
	for(auto &i:dp)for(auto &j:i)j = inf;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	cout<<f(1,n,0);
}