#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n+1];
	bool done[n+1] = {};
	for(int i =1;i<=n;i++)cin>>arr[i],done[arr[i]] = true;
	vector<int> v1,v2;
	for(int i = 1;i<=n;i++){
		if(!arr[i])v1.push_back(i);
		if(!done[i])v2.push_back(i);
	}
	for(int i = 0;i<v1.size();i++){
		arr[v1[i]] = v2[i];
	}
	if(v1.size() == 0){
		for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<'\n';
		return;
	}
	if(arr[v1[0]] == v1[0]){
		swap(arr[v1[0]],arr[v1[1]]);
	}
	for(int i = 1;i<v1.size();i++){
		if(arr[v1[i]] == v1[i]){
			swap(arr[v1[i]],arr[v1[i-1]]);
		}
	}
	for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<'\n';
	for(int i = 1;i<=n;i++)assert(arr[i] != i);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
