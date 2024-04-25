#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin>>n>>s;
	if(s.size()>=3){
		cout<<"NO\n";
	}
	else if(s.size()==2&&s[0] == s[1])cout<<"NO\n";
	else cout<<"YES\n";
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
