#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string s;
	int p;
	cin>>s>>p;
	vector<int> v;
	vector<int> st;
	int n = s.size();
	for(int i = 0;i<n;i++){
		while(!st.empty()&&s[st.back()]>s[i]){
			v.push_back(st.back());
			st.pop_back();
		}
		st.push_back(i);
	}
	while(!st.empty()){
		v.push_back(st.back());
		st.pop_back();
	}
	if(p<=n){
		cout<<s[p-1];
		return;
	}
	p--;
	int lvl = -1;
	for(int i = n;i>=1;i--){
		if(p>=i){
			p -= i;
			lvl++;
		}
		else break;
	}
	//cout<<s<<'\n';
	//cout<<lvl<<":"<<p<<'\n';
	set<int> del;
	for(int i = 0;i<=lvl;i++)del.insert(v[i]);
	string tmp;
	for(int i = 0;i<n;i++){
		if(del.find(i) != del.end())continue;
		tmp += s[i];
	}
	cout<<tmp[p];
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
