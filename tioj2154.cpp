#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	int t;
	cin>>t;
	int n = t;
	t--;
	set<char> st;
	string in;
	cin>>in;
	int cnt[30] = {};
	for(auto &i:in)st.insert(i);
	for(auto i:st)cnt[i-'a']++;
	while(t--){
		string s;
		cin>>s;
		set<char> ss;
		for(auto &i:s)ss.insert(i);
		for(auto &i:ss)cnt[i-'a']++;
	}
	bool flag = false;
	for(int i = 0;i<30;i++){
		if(cnt[i] == n){
			cout<<(char)('a'+i);
			return 0;
		}
	}
	cout<<"7122";
}

