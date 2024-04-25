#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(mp.count(k) == 0)mp[k] = 1;
		else mp[k]++;
	}
	vector<int> v;
	for(auto it = mp.begin();it != mp.end();it++){
		v.push_back(it->second);
	}
	sort(v.begin(),v.end());
	int pref = 0;
	for(int i:v)pref+=i;
	int ans = INT_MAX;
	int m = v.size();
	for(int i = 0;i<m;i++){
		ans = min(ans,pref-(m-i)*v[i]);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
