#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	string s;
	cin>>s;
	stack<char> st;
	for(auto &i:s){
		if(st.empty()||st.top() != i)st.push(i);
		else st.pop();
	}
	string tmp;
	while(!st.empty()){
		tmp += st.top();
		st.pop();
	}
	reverse(tmp.begin(),tmp.end());
	cout<<tmp;
}

