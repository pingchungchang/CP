#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	cout<<s;
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
