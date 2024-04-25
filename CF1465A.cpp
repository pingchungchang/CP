#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	int p = n-1;
	while(p>=0&&s[p] == ')')p--;
	if(p+1>=n-p-1)cout<<"no\n";
	else cout<<"yes\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
