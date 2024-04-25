#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	map<int,vector<int>> mp;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k].push_back(i);
	}
	int now = 0;
	for(auto it = mp.begin();it != mp.end();it++){
		vector<int> v = it->second;
		int evens = 0;
		int odds = 0;
		for(int i:v){
			int dif = abs(i-now);
			if((dif)&1)odds++;
			else evens++;
		}
		if(evens-odds>1||evens-odds<0){
			cout<<"NO\n";
			return;
		}
		now+= v.size();
	}
	cout<<"YES\n";
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
