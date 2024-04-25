#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> ans;
	int arr[n];
	int brr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++)brr[i] = arr[i];
	auto shift = [&](int st){
		swap(arr[st+1],arr[st+2]);
		swap(arr[st],arr[st+1]);
		ans.push_back(st);
	};
	for(int i = 0;i<=n*2;i++){
		for(int j = 0;j<n-2;j++){
			if(arr[j+2] != *max_element(arr+j,arr+j+3))shift(j);
		}
	}
	bool flag = true;
	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1]){
			flag = false;
			break;
		}
	}
	if(flag){
		cout<<ans.size()<<'\n';
		for(auto &i:ans)cout<<i+1<<' ';cout<<'\n';
		return;
	}
	ans.clear();
	for(int i = 0;i<n;i++)arr[i] = brr[i];
	for(int i = 0;i<=n*2;i++){
		for(int j = n-3;j>=0;j--){
			if(arr[j] != *min_element(arr+j,arr+j+2))shift(j);
		}
	}
	flag = true;
	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1])flag = false;
	}
	if(flag){
		cout<<ans.size()<<'\n';
		for(auto &i:ans)cout<<i+1<<' ';cout<<'\n';
		return;
	}
	cout<<"-1\n";
	return;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
