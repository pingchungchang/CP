#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,x;
	cin>>n>>x;
	int arr[n];
	int sum = 0;
	bool flag = true;
	int flag2 = false;
	for(auto &i:arr){
		cin>>i;
		if(i != x)flag = false;
		if(i == x)flag2 = true;
		sum += i-x;
	}
	if(flag){
		cout<<"0\n";
		return;
	}
	else if(sum == 0)cout<<"1\n";
	else cout<<2-flag2<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
