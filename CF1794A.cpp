#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	set<string> st;
	set<int> lens;
	for(int i = 0;i<n*2-2;i++){
		string ss;
		cin>>ss;
		if(lens.find(ss.size()) != lens.end())reverse(ss.begin(),ss.end());
		st.insert(ss);
		lens.insert(ss.size());
	}
	if(st.size() == n-1)cout<<"Yes\n";
	else cout<<"No\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
