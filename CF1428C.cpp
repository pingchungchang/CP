#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	string s;
	cin>>s;
	stack<char> st;
	for(auto i:s){
		if(i == 'B'&&!st.empty())st.pop();
		else st.push(i);
	}
	cout<<st.size()<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

