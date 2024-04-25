#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	string ans;
	int now = n;
	int add = 2;
	while(now>=add){
		ans += '0'+add;
		now -= add;
		add = 3-add;
	}
	if(now == 0){
		cout<<ans<<'\n';
		return;
	}
	ans = "";
	now= n,add =1;
	while(now>=add){
		ans += '0'+add;
		now -= add;
		add = 3-add;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
