#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int change[n] = {};
	int l = n,r = 0;
	for(int i = 0;i<n/2;i++){
		if(s[i] != s[n-1-i])change[i] = 1,l = min(l,i),r = max(r,i);
	}
	int cnt = 0;
	for(int i = l;i<=r;i++){
		cnt += change[i];
	}
	if(r-l+1 == cnt||r<l)cout<<"YES\n";
	else cout<<"No\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
