#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
int lpf[mxn];

void solve(){
	map<vector<int>,int> mp;
	int n;
	cin>>n;
	int arr[n];
	vector<int> v[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++){
		int tmp = arr[i];
		while(tmp != 1){
			if(!v[i].empty()&&v[i].back() == lpf[tmp])v[i].pop_back();
			else v[i].push_back(lpf[tmp]);
			tmp/=lpf[tmp];
		}
		mp[v[i]]++;
	}
	/*
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<":";for(auto &j:v[i])cout<<j<<' ';cout<<'\n';
	}

   */
	int q;
	cin>>q;
	ll req[q] = {},ans[q];
	for(auto &i:req)cin>>i;
	int tans = 0;
	for(auto &i:mp)tans = max(tans,i.sc);
	for(int i = 0;i<q;i++){
		if(!req[i])ans[i] = tans;
	}
	int sum = n;
	tans = 0;
	for(auto &i:mp){
		if(i.fs.empty())continue;
		if(i.sc&1)sum -= i.sc,tans = max(tans,i.sc);
	}
	tans = max(tans,sum);
	for(int i = 0;i<q;i++){
		if(req[i])ans[i] = tans;
	}
	for(auto &i:ans)cout<<i<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	lpf[0] = lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
