#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

map<ll,ll> mp;

void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		ll c,s;
		cin>>c>>s;
		mp[s] = c;
	}
	ll m;
	cin>>m;
	pll arr[m];
	for(auto &i:arr)cin>>i.sc>>i.fs;
	sort(arr,arr+m);
	for(auto &i:arr)swap(i.fs,i.sc);
	ll dp[m][3],pre[m][3];
	memset(pre,-1,sizeof(pre));
	memset(dp,0LL,sizeof(dp));
	if(mp[arr[0].sc]<=arr[0].fs)dp[0][1] = mp[arr[0].sc];
	if(mp[arr[0].sc+1]<=arr[0].fs)dp[0][2] = mp[arr[0].sc+1];
	for(int i = 1;i<m;i++){

	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
