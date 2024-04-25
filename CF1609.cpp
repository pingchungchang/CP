#include <bits/stdc++.h>
using namespace std;


string s;
set<int> st;
void solve(){
	int pos;
	char c;
	cin>>pos>>c;
	pos--;
	if(s[pos] == c){
		cout<<st.size()<<'\n';
		return;
	}
	s[pos] = c;
	for(int i = max(pos-2,0);i<=min(pos+2,(int)s.size()-3);i++){
		if(st.find(i)!= st.end()){
			st.erase(i);
		}
		if(s.substr(i,3) == "abc"){
			st.insert(i);
		}
	}
	cout<<st.size()<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	cin>>s;
//	cout<<1;
	if(n>=3){
		for(int i = 0;i<s.size()-2;i++){
			if(s.substr(i,3) == "abc"){
				st.insert(i);
			}
		}	
	}
	for(int i = 0;i<q;i++){
		solve();
	}
}
