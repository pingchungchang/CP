#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i =0;i<n;i++){
		string s;
		cin>>s;
		if((s.size()&1) == 0&&s.substr(0,s.size()/2) == s.substr(s.size()/2,s.size()/2)){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
}
