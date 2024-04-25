#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	io
	set<string> st;
	string s;
	while(cin>>s){
//		if(s == "-1")return 0;
		auto it = st.insert(s);
		cout<<(1^it.second)<<'\n';
	}
}

