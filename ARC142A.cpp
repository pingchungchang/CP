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
	ll n,k;
	cin>>n>>k;
	string s = to_string(k);
	string rs = s;
	reverse(rs.begin(),rs.end());
	if(stoll(rs)<stoll(s)){
		cout<<0;
		return 0;
	}
	set<string> st;
	while(stoll(s)<=n){
		st.insert(s);
		s += '0';
	}
	while(stoll(rs)<=n){
		st.insert(rs);
		rs += '0';
	}
	cout<<st.size();
}

