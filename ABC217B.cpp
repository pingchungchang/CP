#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	set<string> st;
	st.insert("AGC");
	st.insert("ARC");
	st.insert("ABC");
	st.insert("AHC");
	for(int i = 0;i<3;i++){
		string s;
		cin>>s;
		st.erase(s);
	}
	cout<<*st.begin();
}

