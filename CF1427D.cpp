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
	int arr[n+1] = {};
	int pos[n+1] = {};
	for(int i = 1;i<=n;i++)cin>>arr[i],pos[arr[i]] = i;
	bool flag = false;
	vector<vector<int>> ans;
	for(int i = 1;i<n;i++){
		if(pos[i] == i)continue;
		ans.push_back({});
		for(int j = 1;j<i;j++)ans.back().push_back(1);
		ans.back().push_back(pos[i]-i+1);
		for(int j = pos[i]+1;j<=n;j++)ans.back().push_back(1);
		if(flag)reverse(ans.back().begin(),ans.back().end());
		flag ^= 1;
		reverse(arr+i,arr+pos[i]+1);
		for(int j = 1;j<=n;j++)pos[arr[j]] = j;
		//for(int j = 1;j<=n;j++)cout<<arr[j]<<' ';cout<<'\n';
	}
	if(!ans.empty()&&ans[0].size() == 1)ans.erase(ans.begin());
	if(flag){
		ans.push_back({});
		for(int i = 1;i<=n;i++)ans.back().push_back(1);
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans){
		cout<<i.size()<<' ';
		for(auto &j:i)cout<<j<<' ';cout<<'\n';
	}
	return 0;
}
