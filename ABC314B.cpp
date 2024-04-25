#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	set<int> v[n+1];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int tmp;
			cin>>tmp;
			v[i].insert(tmp);
		}
	}
	int tar;
	cin>>tar;
	pair<int,vector<int>> ans;
	ans.fs = 1e9;
	for(int i = 1;i<=n;i++){
		if(v[i].find(tar) != v[i].end()){
			if(v[i].size() == ans.fs)ans.sc.push_back(i);
			else if(v[i].size()<ans.fs)ans.sc = {i},ans.fs = v[i].size();
		}
	}
	cout<<ans.sc.size()<<'\n';
	for(auto &i:ans.sc)cout<<i<<' ';
	return 0;
}
