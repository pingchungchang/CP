//fail
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	string s;
	cin>>s;
	set<string> st;
	for(int i = 0;i<s.size();i++){
		string ss;
		for(int j = i;j<s.size();j++){
			ss += s[j];
			if(st.find(ss)== st.end())st.insert(ss);
		}
	}
	cout<<st.size()<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
}


