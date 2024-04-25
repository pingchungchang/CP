#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


map<vector<int>,ll> dp[2];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k,p;
	cin>>n>>k>>p;
	vector<int> v(k,0);
	bool roll = 0;
	dp[roll][v] = 0;
	for(int i = 0;i<n;i++){
		roll^=1;
		dp[roll].clear();
		ll C;
		cin>>C;
		vector<int> add(k);
		for(auto &j:add)cin>>j;
		for(auto &j:dp[roll^1]){
			auto tmp = j.fs;
			if(dp[roll].find(tmp) == dp[roll].end())dp[roll][tmp] = j.sc;
			else dp[roll][tmp] = min(dp[roll][tmp],j.sc);

			for(int l = 0;l<k;l++){
				tmp[l] = min(p,tmp[l]+add[l]);
			}
			if(dp[roll].find(tmp) == dp[roll].end())dp[roll][tmp] = C+j.sc;
			else dp[roll][tmp] = min(dp[roll][tmp],C+j.sc);
		}
	}
	for(auto &i:v)i = p;
	/*
	for(auto &i:dp[roll]){
		for(auto &j:i.fs)cout<<j<<' ';cout<<":"<<i.sc<<endl;
	}

   */
	if(dp[roll].find(v) == dp[roll].end())cout<<-1;
	else cout<<dp[roll][v];
}
