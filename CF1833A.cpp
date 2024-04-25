#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	set<string> st;
	for(int i = 1;i<n;i++){
		st.insert(s.substr(i-1,2));
	}
	cout<<st.size()<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
