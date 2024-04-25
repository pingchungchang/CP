#include <bits/stdc++.h>
using namespace std;

void modify(int &a,int &b){
	if((a+b)&1)b = a;
	else a = b;
	return;
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	if(n == 1){
		cout<<0<<'\n';
		return;
	}
	vector<pair<int,int>> ans;
	ans.push_back({0,n-1});
	modify(arr[0],arr[n-1]);
	for(int i = 1;i<n-1;i++){
		if((arr[i]+arr[0])&1){
			modify(arr[0],arr[i]);
			ans.push_back({0,i});
		}
		else{
			modify(arr[i],arr[n-1]);
			ans.push_back({i,n-1});
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.first+1<<' '<<i.second+1<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
