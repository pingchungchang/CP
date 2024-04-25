#include <bits/stdc++.h>
using namespace std;

void solve(){
	vector<int> v(3);
	for(int i = 0;i<3;i++)cin>>v[i];
	sort(v.begin(),v.end());
	int sum = v[0]+v[1]+v[2];
	if(v[1] == v[0]||v[1] == v[2]){
		if((sum-2*v[1])%2 == 0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	else{
		if(v[2] == v[1]+v[0])cout<<"YES\n";
		else cout<<"NO\n";
	}
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}
