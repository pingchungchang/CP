#include <bits/stdc++.h>
using namespace std;

pair<int,string> calc(string s,int len){
	vector<int> change;
	vector<int> v[26];
	for(int i = 0;i<s.size();i++){
		v[s[i]-'a'].push_back(i);
	}
	vector<pair<int,int>> vv;
	for(int i = 0;i<26;i++){
		vv.push_back({(int)v[i].size(),i});
	}
	sort(vv.rbegin(),vv.rend());
	int cnt = s.size()/len;
	for(int i = 0;i<cnt;i++){
		int pos = vv[i].second;
		while(v[pos].size()>len){
			change.push_back(v[pos].back());
			v[pos].pop_back();
		}
	}
	for(int i = cnt;i<26;i++){
		int pos = vv[i].second;
		while(!v[pos].empty()){
			change.push_back(v[pos].back());
			v[pos].pop_back();
		}
	}
	int re = change.size();
	for(int i = 0;i<cnt;i++){
		int pos = vv[i].second;
		while(v[pos].size()<len){
			s[change.back()] = 'a'+pos;
			v[pos].push_back(change.back());
			change.pop_back();
		}
	}
	return make_pair(re,s);
}

void solve(){
	int n;
	string s;
	cin>>n>>s;
	map<char,vector<int>> mp;
	pair<int,string> ans = {1e9,""};
	for(int i = 1;i<=26;i++){
		if(n%i != 0)continue;
		ans = min(ans,calc(s,n/i));
	}
	cout<<ans.first<<'\n'<<ans.second<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
