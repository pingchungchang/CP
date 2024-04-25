#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	pair<int,int> arr[3];
	for(auto &i:arr)cin>>i.first>>i.second;
	sort(arr,arr+3);
	int x,y;
	cin>>x>>y;
	for(auto &i:arr){
		if(i.first == x&&i.second == y)continue;
	}
	int cid = -1;
	for(int i = 0;i<3;i++){
		int adj = 0;
		for(int j = 0;j<3;j++){
			if(i == j)continue;
			if(arr[i].first == arr[j].first||arr[i].second == arr[j].second)adj++;
		}
		if(adj == 2)cid = i;
	}
	pair<int,int> corner[] = {{1,1},{n,1},{1,n},{n,n}};
	for(auto &i:corner){
		if(arr[cid].first == i.first&&arr[cid].second == i.second){
			if(x == arr[cid].first||y == arr[cid].second)cout<<"YES\n";
			else cout<<"NO\n";
			return;
		}
	}
	if(x%2 == arr[cid].first%2||y%2 == arr[cid].second%2)cout<<"YES\n";
	else cout<<"NO\n";
	return;
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
