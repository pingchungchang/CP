#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	bool flag = true;
	for(int i = 0;i<n;i++){
		if(arr[i] != i+1)flag = false;
	}
	if(flag)cout<<"0\n";
	else if(arr[0] == 1||arr[n-1] == n)cout<<"1\n";
	else if(arr[0] == n&&arr[n-1] == 1)cout<<"3\n";
	else cout<<"2\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
