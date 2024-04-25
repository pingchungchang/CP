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
	set<char> st;
	bool b= false,ss = false;
	for(auto i:s){
		if(st.find(i) != st.end()){
			cout<<"No";
			return 0;
		}
		st.insert(i);
		if(i>='A'&&i<='Z')b = true;
		else ss = true;
	}
	if(ss&&b)cout<<"Yes";
	else cout<<"No";
}

