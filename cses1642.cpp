#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	set<pair<ll,pair<int,int>>> st;
	int n;
	ll m;
	cin>>n>>m;
	pair<ll,int> arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i].first;
		arr[i].second = i+1;
	}
	map<ll,pair<int,int>> mp;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			mp[arr[i].first+arr[j].first] = make_pair(arr[i].second,arr[j].second);
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			ll now = m-arr[i].first-arr[j].first;
			if(mp.count(now) == 0)continue;
			pair<int,int> others = mp[now];
			if(others.first != arr[j].second&&others.first != arr[i].second&&others.second != arr[i].second&&others.second != arr[j].second){
				cout<<others.first<<' '<<others.second<<' '<<arr[i].second<<' '<<arr[j].second;
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}
