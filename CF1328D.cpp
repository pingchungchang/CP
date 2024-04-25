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
	int arr[n];
	for(auto &i:arr)cin>>i;
	int same = true;
	for(auto &i:arr)if(i != arr[0])same = false;
	if(same){
		cout<<"1\n";
		for(auto &i:arr)cout<<1<<' ';cout<<'\n';
		return;
	}
	same = -1;
	for(int i = 1;i<n;i++)if(arr[i] == arr[i-1])same = i;
	if(arr[n-1] == arr[0])same = 0;
	if(n%2 == 0){
		cout<<"2\n";
		for(int i = 0;i<n;i++){
			if(i&1)cout<<"1 ";
			else cout<<"2 ";
		}
		cout<<'\n';
		return;
	}
	if(same != -1){
		cout<<"2\n";
		int ans[n] = {};
		for(int i = 0;i<n;i++){
			if(i&1)ans[i] = 1;
			else ans[i] = 0;
		}
		if(same == 0);
		else{
			for(int i = same;i<n;i++)ans[i] ^= 1;
		}
		for(auto &i:ans)cout<<i+1<<' ';cout<<'\n';
		return;
	}
	cout<<"3\n";
	int ans[n];
	for(int i = 0;i<n;i++){
		ans[i] = i&1;
	}
	ans[n-1] = 2;
	for(auto &i:ans)cout<<i+1<<' ';
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
