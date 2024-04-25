#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	if(s == "^"){
		cout<<1<<'\n';
		return;
	}
	int cnt = 0;
	int ans = 0;
	bool flag = true;
	for(auto &i:s){
		if(i == '_')cnt++;
		else{
			if(flag)ans += cnt;
			else ans += max(0,cnt-1);
			flag = false;
			cnt = 0;
		}
	}
	if(flag)ans++;
	ans += cnt;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
