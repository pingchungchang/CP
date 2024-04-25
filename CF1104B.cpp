#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	string s;cin>>s;
	stack<char> st;
	int ans =0;
	for(auto i:s){
		if(st.empty()||st.top() != i){
			st.push(i);
		}
		else{
			st.pop();
			ans++;
		}
	}
	if(ans&1){
		cout<<"Yes";
	}
	else cout<<"No";
}

