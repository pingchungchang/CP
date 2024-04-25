#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	string s;
	cin>>s;
	stack<char> st;
	st.push('o');
	st.push('l');
	st.push('l');
	st.push('e');
	st.push('h');
	for(auto i:s){
		if(!st.empty()&&i == st.top())st.pop();
	}
	if(st.empty())cout<<"YES";
	else cout<<"NO";
}

