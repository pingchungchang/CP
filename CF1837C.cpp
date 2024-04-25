#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	bool flag = true;
	for(auto &i:s){
		if(i != '?')flag = false;
	}
	if(flag){
		for(auto &i:s)i = '0';
		cout<<s<<'\n';
		return;
	}
	set<pii> st;
	for(int i = 0;i<s.size();i++){
		if(s[i] != '?')st.insert({i,s[i]-'0'});
	}
	for(int i = 0;i<s.size();i++){
		if(s[i] == '?'){
			auto it = st.lower_bound(make_pair(i,0));
			if(it == st.end())it--;
			//cout<<i<<":"<<it->fs<<' '<<it->sc<<',';
			s[i] = '0'+it->sc;
		}
	}
	cout<<s<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
