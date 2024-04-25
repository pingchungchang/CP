#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	set<string> all;
	set<string> st;
	bool ans = false;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		if(s.size() == 1)ans = true;
		else if(s.size() == 2){
			st.insert(s);
			all.insert(s);
			reverse(s.begin(),s.end());
			if(st.find(s) != st.end())ans = true;
		}
		else{
			all.insert(s);
			st.insert(s.substr(0,2));
			reverse(s.begin(),s.end());
			if(all.find(s.substr(0,2)) != all.end()||all.find(s) != all.end())ans = true;
			reverse(s.begin(),s.end());
			if(s[0] == s[1] &&s[1] == s[2])ans = true;
		}
	}
	if(ans)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
/*
3
ca
bcb
ca
*/

