#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string arr[n];
	for(auto &i:arr)cin>>i;
	pair<string,int> brr[m];
	for(auto &i:brr)cin>>i.fs;
	int p;
	cin>>p;
	for(auto &i:brr)cin>>i.sc;
	map<string,int> mp;
	for(auto &i:brr)mp[i.fs] = i.sc;
	int ans = 0;
	for(auto &i:arr){
		if(mp.find(i) == mp.end())ans += p;
		else ans += mp[i];
	}
	cout<<ans;
}
