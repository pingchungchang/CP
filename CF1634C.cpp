#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	if((n&1)&&k != 1){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	int c = 2;
	for(int i = 0;i<n/2;i++){
		for(int j = 0;j<k;j++)cout<<c<<' ',c+=2;
		cout<<'\n';
	}
	c = 1;
	for(int i = n/2;i<n;i++){
		for(int j = 0;j<k;j++)cout<<c<<' ',c+=2;
		cout<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
