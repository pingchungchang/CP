#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	vector<pair<int,int>> v;
	int l = n,r = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == '0')l = min(l,i),r = max(r,i);
	}
	if(l>=r){
		cout<<0<<'\n';
		return;
	}
	int cnt = 0;
	int ans = 0;
	for(int i = l+1;i<=r;i++){
		if(s[i] == '0'){
			ans += max(0,2-cnt);
			cnt = 0;
		}
		else cnt++;
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
