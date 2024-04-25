#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	vector<pii> change;
	string s;
	cin>>s;
	for(int i = 1;i<s.size();i++){
		if(s[i] == s[i-1])change.push_back({i-1,i});
		if(i>1&&s[i] == s[i-2])change.push_back({i-2,i});
	}
	sort(change.begin(),change.end());
	set<int> st;
	for(auto &i:change){
		if(st.find(i.fs) == st.end()&&st.find(i.sc) == st.end()){
			st.insert(i.sc);
		}
	}
	cout<<st.size()<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
