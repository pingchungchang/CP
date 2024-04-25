#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	map<int,int> mp;
	vector<int> v[n];
	for(auto &i:v){
		int k;
		cin>>k;
		while(k--){
			int t;
			cin>>t;
			i.push_back(t);
			mp[t]++;
		}
	}
	for(auto &i:v){
		bool flag = true;
		for(auto &j:i){
			if(mp[j] == 1)flag = false;
		}
		if(flag){
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
