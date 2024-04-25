#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int> v[n+1];
	vector<pair<int,int>> arr;
	for(int i = 0;i<n*3;i++){
		int k;
		cin>>k;
		v[k].push_back(i);
	}
	for(int i = 1;i<=n;i++)arr.push_back({v[i][1],i});
	sort(arr.begin(),arr.end());
	for(auto &i:arr)cout<<i.sc<<' ';
}
