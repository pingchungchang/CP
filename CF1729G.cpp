#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mod = 1e9+7;
const int mxn = 505;
pii dp[mxn];

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}
inline int mub(int a,int b){
	return mad(a,mod-b);
}

void solve(){
	string s,t;
	cin>>s>>t;
	vector<int> v;
	v.push_back(-mxn);
	for(int i = 0;i+t.size()<=s.size();i++){
		if(s.substr(i,t.size()) == t)v.push_back(i);
	}
	int n = v.size()-1;
	for(int i = 0;i<=n+1;i++){
		dp[i] = {mxn,0};
	}
	dp[0] = {0,1};
	auto covered = [&](int l,int r){
		for(int i = l+1;i<r;i++){
			//cout<<v[l]<<' '<<v[l]+(int)t.size()<<":"<<v[i]<<";"<<v[i]+t.size()<<':'<<v[r]<<'\n';
			if(v[l]+(int)t.size()<=v[i]&&v[i]+t.size()<=v[r])return false;
		}
		return true;
	};
	for(int i = 1;i<=n;i++){
		for(int j = i-1;j>=0;j--){
			if(covered(j,i)&&v[i]-v[j]>=t.size())dp[i].fs = min(dp[j].fs+1,dp[i].fs);
		}
		for(int j = i-1;j>=0;j--){
			if(covered(j,i)&&v[i]-v[j]>=t.size()){
				//cout<<i<<':'<<j<<'\n';
				if(dp[i].fs == dp[j].fs+1)dp[i].sc = mad(dp[i].sc,dp[j].sc);
			}
		}
	}
	/*
	for(auto &i:v)cout<<i<<',';cout<<'\n';
	for(int i= 0;i<=n;i++)cout<<dp[i].fs<<','<<dp[i].sc<<' ';cout<<'\n';

   */
	pii ans = {mxn,0};
	for(int i = 0;i<=n;i++){
		if(v[i]+(int)t.size()>v.back()){
			if(ans.fs>dp[i].fs)ans = dp[i];
			else if(ans.fs == dp[i].fs)ans.sc = mad(ans.sc,dp[i].sc);
		}
	}
	cout<<ans.fs<<' '<<ans.sc<<'\n';
	/*
	for(int i = 0;i<=n;i++){
		if(v[i]+(int)t.size()>v.back()){
			if(ans.fs == dp[i].fs)cout<<i<<','<<dp[i].sc<<' ';
		}
	}cout<<'\n';

   */
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
