#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	string s;
	cin>>s;
	stack<char> st;
	for(auto &i:s){
		if(i == ')'){
			if(st.empty()){
				cout<<"N\n";
				return;
			}
			st.pop();
		}
		else st.push('(');
	}
	if(st.empty())cout<<"Y\n";
	else cout<<"N\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

