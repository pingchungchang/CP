#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int calc(int len){
	if(len<=0)return 0;
	if(len == 1)return 1;
	int re = 0;
	while(len>0){
		re++;
		len = len/2;
	}
	return re;
}

void solve(){
	string s;
	cin>>s;
	int n = s.size();
	vector<int> pos[26];
	for(int i = 0;i<s.size();i++){
		pos[s[i]-'a'].push_back(i);
	}
	for(int i = 0;i<26;i++){
		if(pos[i].size() == s.size()){
			cout<<"0\n";
			return;
		}
	}
	int ans = n;
	for(int i = 0;i<26;i++){
		if(pos[i].empty())continue;
		int re = calc(pos[i][0]);
		for(int j = 1;j<pos[i].size();j++)re = max(re,calc(pos[i][j]-pos[i][j-1]-1));
		re = max(re,calc(n-1-pos[i].back()));
		//cout<<i<<":"<<re<<',';
		ans = min(ans,re);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
