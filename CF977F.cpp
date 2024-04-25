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
	int arr[n+1];
	pii dp[n+1];
	for(auto &i:dp)i = {1,0};
	map<int,pair<int,int>> mp;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		if(mp.find(arr[i]-1) != mp.end()){
			dp[i] = {mp[arr[i]-1].fs+1,mp[arr[i]-1].sc};
		}
		mp[arr[i]] = max(mp[arr[i]],{dp[i].fs,i});
	}
	pii big = {0,0};
	for(auto &i:mp)big = max(big,i.sc);
	vector<int> v;
	while(big.sc){
		v.push_back(big.sc);
		big = dp[big.sc];
	}
	reverse(v.begin(),v.end());
	cout<<v.size()<<'\n';
	for(auto &i:v)cout<<i<<' ';return 0;
}
