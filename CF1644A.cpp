#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	set<char> st;
	for(int i = 0;i<s.size();i++){
		if(s[i]>'a'){
			st.insert('A'+(s[i]-'a'));
		}
		else if(st.find(s[i]) == st.end()){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
