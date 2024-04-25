#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 404;
vector<int> paths[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int cnt[26] = {};
	pii range[26];
	for(auto &i:range)i = {n+1,0};
	string s;
	cin>>s;
	s = "#"+s;
	vector<vector<int>> v;
	int ans[n+1] = {};
	for(int i = 1;i<=n;i++){
		bool flag = false;
		for(auto &j:v){
			if(s[j.back()]<=s[i]){
				j.push_back(i);
				flag = true;
				break;
			}
		}
		if(!flag)v.push_back({i});
		for(int j= 0;j<v.size();j++){
			for(int k = 1;k<v.size();k++){
				if(s[v[k].back()]>s[v[k-1].back()])swap(v[k],v[k-1]);
			}
		}
	}
	for(int i = 0;i<v.size();i++){
		for(auto &j:v[i])ans[j] = i+1;
	}
	if(v.size()>2)cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(int i = 1;i<=n;i++)cout<<ans[i]-1;return 0;
	}
	/*
	cout<<v.size()<<'\n';
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
   */
}
