#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n+1] = {};
	bool flag = true;
	int same = 0;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		if(i != arr[i])flag = false;
		else same++;
	}
	if(flag){
		cout<<0<<'\n';
		return;
	}
	int s = 1;
	while(s == arr[s])s++;
	int e = n;
	while(e == arr[e])e--;
	if(n-same == e-s+1)cout<<"1\n";
	else cout<<"2\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
